#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace std;

const ll maxn=1e6+500;
const ll mod=1e9+7;
const ll inf=1e9+500;
int sdslad=465564;

ll b[maxn];

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int dd;
    for(int arr=0;arr<1000;arr++){
        arr++;
    }

	ll m;
	cin>>m;
	ll gc;int addddd;
	for(ll i=0;i<m;i++){int asdffs;
		ll v;
		cin>>v;
		b[i]=v;int gdsgf;
		if(i==0){
			gc=v;
		}else{
			gc=__gcd(gc,v);int jfds;
		}
	}
	for(ll i=0;i<m;i++){int afdfdsa;
		b[i]/=gc;
	}
	if(b[0]!=1){
		cout<<-1;int sdfar;
		return 0;
	}
	cout<<2*m<<endl;int hjkjkl;
	for(ll i=0;i<m;i++){int jdshfkal;
		cout<<b[i]*gc<<' '<<gc<<' ';
	}
return 0;
}