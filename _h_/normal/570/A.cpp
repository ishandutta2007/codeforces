#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)

int main(){
	int n,m;
	cin >> n >> m;
	int cit[101] = {};
	int rekcit = -1;
	rep(i,0,m){
		int cand[101] = {};
		int rek = -1;
		rep(j,0,n){
			cin >> cand[j];
			rek = max(rek,cand[j]);
		}
		rep(j,0,101)
			if(cand[j] == rek){
				rekcit = max(rekcit,++cit[j]);
				break;
			}
	}
	rep(j,0,101)
		if(cit[j] == rekcit){
			cout << j+1 << endl;
			return 0;
		}
}