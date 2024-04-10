#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sort(x) sort(all(x))
#define rev(x) reverse(all(x))

char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;

#ifdef __WIN64
	#define gc getchar()
#else
	#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#endif
#define pc(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)

inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x){
	if(x>9)print(x/10);
	pc(x%10+'0');
}

const int N=1e6+5;
const int inf=0x3f3f3f3f;
string s;
int buc[N<<1],len,num;
int main(){
	cin>>s;
	int pre=0;
	memset(buc,0x3f,sizeof(buc));
	buc[N]=-1;
	for(int i=0;i<s.size();i++){
		if(s[i]==')')buc[pre+N]=inf;
		pre+=(s[i]=='('?1:-1);
		if(i-buc[pre+N]>len)len=i-buc[pre+N],num=1;
		else num+=(i-buc[pre+N]==len);
		if(buc[pre+N]==inf)buc[pre+N]=i;
	}
	if(!len)num=1;
	cout<<len<<" "<<num<<endl;
    return 0;
}