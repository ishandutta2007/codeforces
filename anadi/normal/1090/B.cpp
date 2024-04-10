#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

int cnt = 0;
map <string, int> M;
vector <pair <string, string> > Input;

bool cmp(pair <string, string> a, pair <string, string> b){
	return M[a.st] < M[b.st];
}

void add(string &s){
	for(int i = 0; i < s.size(); ++i)
		if(s[i] == '\\'){
			string x;
			for(int j = i + 6; true; ++j){
				if(s[j] == '}')
					break;
				x.push_back(s[j]);
			}
			
			M[x] = ++cnt;
		}
}

int main(){
	ios_base::sync_with_stdio(false);

	string s;
	while(true){
		getline(cin, s);
		bool Text = true;
		
		if(s.size() == 0 || s[0] == ' ')
			continue;
		
		if(s[0] == '\\'){
			if(s[1] == 'e')
				break;
			Text = s[1] != 'b';
		}
		
		if(Text)
			add(s);
		else{
			if(s[2] == 'e')
				continue;

			string x;
			for(int i = 0; i < s.size(); ++i){
				if(s[i] != '{')
					continue;
				
				for(int j = i + 1; true; ++j){
					if(s[j] == '}')
						break;
					x.push_back(s[j]);
				}

				break;
			}

			Input.push_back({x, s});
		}
	}
	
	
	for(int i = 1; i <= cnt; ++i)
		if(M[Input[i - 1].st] != i){
			cout << "Incorrect\n";
			sort(Input.begin(), Input.end(), cmp);
			
			cout << "\\begin{thebibliography}{99}\n";
			for(auto v: Input)
				cout << v.nd << "\n";
			cout << "\\end{thebibliography}\n";
			return 0;
		}
	
	cout << "Correct\n";
	return 0;
}