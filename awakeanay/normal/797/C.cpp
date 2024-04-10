#include <iostream>
#include <stack>
#include <vector>

int main() {
	std::string s;
	std::cin >> s;
	
	int n = s.length();
	
	int last = -1;
	int cur = 0;
	
	std::string t(n, 'a');
	int it = 0;
	
	std::vector<int> done(n, false);
	std::stack<int> rem;
	std::vector<int> end(26, 0);
	
	for(int i = 0; i < n; i++)
		end[s[i]-'a'] = i+1;
	
	while(cur < 26) {
		int next = last;
		int count = 0;
		
		for(int i = last+1; i < end[cur]; i++) {
			if(s[i] == 'a'+cur) {
				count++;
				last = i;
				done[i] = true;
			}
			else if(!done[i]) {
				rem.push(i);
				done[i] = true;
			}
		}
		
		for(int i = 0; i < count; i++)
			t[it++] = (char)('a' + cur);
		
		if(last == n-1)
			break;
		
		cur++;
		
		while(!rem.empty() && s[rem.top()]-'a' <= cur) {
			t[it++] = s[rem.top()];
			done[rem.top()] = true;
			rem.pop();
		}
	}

	
	while(!rem.empty()) {
		t[it++] = s[rem.top()];
		rem.pop();
	}
	
	std::cout << t << std::endl;
	
	return 0;
}