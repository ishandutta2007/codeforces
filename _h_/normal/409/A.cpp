#include <iostream>
#include <vector>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); i++)
typedef vector<int> vi;

int main(){
	cin.sync_with_stdio(0);
	string a,b;
	cin >> a >> b;
	int res = 0;
	rep(i,0,a.size()/2){
		res += a[2*i]=='8' ? (b[2*i]=='['?1:b[2*i]=='('?-1:0) : a[2*i]=='[' ? (b[2*i]=='['?0:b[2*i]=='('?1:-1) : (b[2*i]=='['?-1:b[2*i]=='('?0:1);
	}
	cout << (res == 0 ? "TIE" : res > 0 ? "TEAM 1 WINS" : "TEAM 2 WINS") << endl;
}