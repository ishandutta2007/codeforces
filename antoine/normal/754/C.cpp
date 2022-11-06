#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

std::unordered_set <std::string> users;

int n, m;

bool isAlphaNum(char ch) { return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); }

std::unordered_set <std::string> textToWords(std::string text) {
	std::unordered_set <std::string> words;
	for (size_t i = 0; i < text.size(); ++i) {
		if (isAlphaNum(text[i])) {
			size_t startIdx = i;
			do ++i;
			while (i < text.size() && isAlphaNum(text[i]));
			words.insert(text.substr(startIdx, i - startIdx));
		}
	}
	return words;
}

struct message;
message * messages[100];

struct message {
	std::unordered_set <std::string> senders; // possible senders
	std::string text;
	message(std::string str) {
		int idx = 0;
		while (str[idx] != ':')
			++idx;
		text = str.substr(idx + 1);
		if (str[0] != '?')
			senders.insert(str.substr(0, idx));
		else {
			std::unordered_set <std::string> words = textToWords(text);
			for (auto user : users)
				if (words.find(user) == words.end())
					senders.insert(user);
		}
	}
	bool rem(int idx) {
		if (idx < 0 || idx >= m || messages[idx]->senders.size() != 1)
			return false;
		auto f = senders.find(*messages[idx]->senders.begin());
		if (f == senders.end())
			return false;
		senders.erase(f);
		return true;
	}
};

int main() {
	int t;
	std::cin >> t;
	for (int testCase = 1; testCase <= t; ++testCase) {
		std::cin >> n;
		users.clear();
		for (int i = 0; i < n; ++i) {
			std::string s;
			std::cin >> s;
			users.insert(s);
		}
		std::cin >> m;
		std::string s;
		std::getline(std::cin, s);
		for (int i = 0; i < m; ++i) {
			std::getline(std::cin, s);
			messages[i] = new message(s);
		}

		bool impossible = false;
		for (int i = 0; i < m; ++i) {
			messages[i]->rem(i - 1);
			if (messages[i]->rem(i + 1)) {
				i = std::max(-1, i - 2);
				continue;
			}
			if (messages[i]->senders.size() == 0) {
				std::cout << "Impossible\n";
				impossible = true;
				break;
			}
		}

		if (!impossible)
			for (int i = 0; i < m; ++i) {
				auto it = messages[i]->senders.begin();
				if (messages[i]->senders.size() >= 2) {
					if (i > 0 && it->compare(*messages[i - 1]->senders.begin()) == 0)
						++it;
					std::string sender = *it;
					messages[i]->senders.clear();
					messages[i]->senders.insert(sender);
					it = messages[i]->senders.begin();
				}

				std::cout << *it << ":" << messages[i]->text << "\n";
			}
	}
	return 0;
}