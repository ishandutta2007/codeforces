#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

stack<int> op;
int b;
bool done = false;
void make(int a) {
	if(a == b)
		done = true;
	if(!done && 2*a <= b) {
		op.push(0);
		make(2*a);
		if(!done)
			op.pop();
	}
	if(!done && 10ll*a+1 <= b) {
		op.push(1);
		make(10*a+1);
		if(!done)
			op.pop();
	}
}

int prop(int a) {
	if(!op.empty()) {
		int w = op.top();
		op.pop(); a = prop(a);
		if(w == 0)
			return cout<<2*a<<' ',2*a;
		return cout<<10*a+1<<' ',10*a+1;
	} else
		return cout<<a<<' ',a;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int a; cin>>a>>b;
	make(a);
	if(!done)
		return cout<<"NO",0;
	cout<<"YES\n"<<sz(op)+1<<"\n";
	prop(a);
}