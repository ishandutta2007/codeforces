#include <iostream>
#include <string>

using namespace std;

#define M 100100
string s;
int n,m,a[4][M];

void read(void){
	cin>>s;
	n=s.length();
	for (int i=1; i<=n; ++i){
		for (int j=0; j<3; ++j)
			a[j][i]=a[j][i-1];
		++a[s[i-1]-'x'][i];
	}
}

void kill(void){
	cin>>m;
	for (int i=0,l,r; i<m; ++i){
		cin>>l>>r;
		int x=M,y=-1;
		l--;

		if (r-l<3){
			cout<<"YES\n";
			continue;
		}

		for (int j=0; j<3; ++j)
			x=min(x,a[j][r]-a[j][l]),
			y=max(y,a[j][r]-a[j][l]);

		cout<<(y<=x+1 ? "YES\n":"NO\n");
	}
}

int main(){
#ifdef TROLL
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#else
	ios_base::sync_with_stdio(0);
#endif

	read();
	kill();

	return 0;
}