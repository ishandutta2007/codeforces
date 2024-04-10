#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

string s;
int main(){
	cin >> s;
	//for(int i = 0; i < 78; i++)
	//	s+='a';
	for(int a = 1; a <= 5; a++){
		int b = (s.size() + a - 1) / a;
		int x = b * a - s.size();
		if(b <= 20){
			cout << a << " " << b << endl;
			int cnt = 0;
			for(int i = 0; i < a; i++){
				for(int j = 0; j < b; j++)
					if(cnt < s.size() && !(j == 0 && x-- > 0))
						cout << s[cnt++];
					else
						cout << '*';
				cout << endl;
			}
			return 0;
		}
	}
	return 0;
}