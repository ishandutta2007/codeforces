#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

typedef std::pair<int, int> mypair;
bool comparator(const mypair& l, const mypair& r)
{
	return l.first < r.first;
}

int adapter(int tocast) {
	if (tocast == 1) {
		return 0;
	}
	return (tocast / 2) + (tocast % 2);
}
using namespace std;
int main()
{
	long int n, m ,*computer_from,num_computers=0,num_adapters=0,* sockets;
	cin >> n;
	cin >> m;
	computer_from = new long int[n];
	sockets = new long int[m];
	vector<pair<long int, long int> > pre_sockets(m);
	map<long int, vector<long int>> computers;
	map<long int, vector<long int>>::iterator it;
	for (int i = 0; i < n; i++) {
		computer_from[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		sockets[i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		long int tmp;
		cin >> tmp;
		it = computers.find(tmp);
		if (it == computers.end())
			computers[tmp].push_back(i);// .insert(make_pair(tmp, i));
		else
			it->second.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> pre_sockets[i].first;
		pre_sockets[i].second = i;
	}

	sort(pre_sockets.begin(), pre_sockets.end(), comparator);

	for (int i = 0; i < m; i++) {
		long int energy, adapters=0;
		map<long int, vector<long int>>::iterator it;
		energy = pre_sockets[i].first;
		while (energy != 0) {
			it = computers.find(energy);
			if (it == computers.end() || it->second.empty()) {
				adapters++;
				energy = adapter(energy);
			}
			else {
				int a = it->second.back();
				num_computers++;
				num_adapters += adapters;
				sockets[pre_sockets[i].second] = adapters;
				computer_from[a] = pre_sockets[i].second +1;
				it->second.pop_back();
				break;
			}
		}
	}
	cout << num_computers << " " << num_adapters << '\n' << sockets[0];
	for (int i = 1; i < m; i++) {
		cout << " " << sockets[i];
	}
	cout << '\n' << computer_from[0];
	for (int i = 1; i < n; i++) {
		cout << " " << computer_from[i];
	}
	cout << '\n';
	return 0;
}