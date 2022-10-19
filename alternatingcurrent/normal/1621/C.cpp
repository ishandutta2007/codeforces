#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n;
int p[10010];
bool used[10010];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++)
			used[i] = 0;
		for(int i = 1; i <= n; i++){
			if(!used[i]){
				cout << "? " << i << endl;
				int nowval;
				cin >> nowval;
				while(!used[nowval]){
					used[nowval] = 1;
					int nxtval;
					cout << "? " << i << endl;
					cin >> nxtval;
					p[nowval] = nxtval;
					nowval = nxtval;
				}
			}
		}
		cout << "! ";
		for(int i = 1; i <= n; i++)
			cout << p[i] << " ";
		cout << endl;
	}
	return 0;
}