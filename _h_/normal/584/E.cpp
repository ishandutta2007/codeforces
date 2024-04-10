#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
typedef vector<int> vi;
typedef pair<int,int> pii;
const int mx = 2003;
int main(){
	int n, p[mx], s[mx], ans = 0;
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",p+i);
	rep(i,0,n){
		int a;
		scanf("%d",&a);
		s[a] = i;
	}
	rep(i,0,n){
		p[i] = s[p[i]];
		ans += abs(p[i]-i);
	}
	printf("%d\n",ans/2);
	vector<pii> svar;
	rep(i,0,n){
		int pos;
		rep(j,i,n) if(p[j] == i){
			pos = j;
			break;
		}
		while(pos != i){
			for(int j = pos-1; ; --j){
				if(p[j] >= pos){
					svar.push_back(pii(j,pos));
					swap(p[j],p[pos]);
					pos = j;
					break;
				}
			}
		}
	}
	printf("%d\n",(int)svar.size());
	for(pii &p : svar)
		printf("%d %d\n",p.first+1,p.second+1);
}