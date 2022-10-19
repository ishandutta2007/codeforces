#include <iostream>
#include <string>

#define L 100100
#define N 53
#define A 2
#define mod 1000000007

using namespace std;

int n,m,d[L],b[A],len,p[L],link[A][L],de[A],l[A],fl[N];
string f[N],s,a[A],ps,h[A];

void pre(void){
	f[1]="a";
	f[2]="b";
	for (int i=3; f[i-1].length()<2*L; ++i)
	f[i]=f[i-1]+f[i-2],m=i;
	a[m%2]=f[m];
	a[(m-1)%2]=f[m-1];
	
	for (int i=0; i<2; ++i){
		h[i]=a[i]+f[m];
		de[i]=a[i].length();
		l[i]=h[i].length();
	}
	
	fl[1]=fl[2]=1;
	for (int i=3; i<=m; ++i)
	fl[i]=fl[i-1]+fl[i-2];
	
}

void cmp(void){
	len=s.length();
	
	for (int i=1; i<len; ++i){
		int j=p[i-1];
		while (j>0 && s[j]!=s[i])
		j=p[j-1];
		if (s[j]==s[i])
		j++;
		p[i]=j;
	}
	
	for (int j=0; j<A; ++j)
	for (int i=0; i<=len; ++i){
		char ch='a'+j;
		if (i<len && s[i]==ch)
		link[j][i]=i+1;
		else
		link[j][i]= i>0 ? link[j][p[i-1]]:0;
	}
}

void pre_calc(void){
	b[0]=b[1]=0;
	
	for (int i=0,st=0; i<2; ++i,st=0)
	for (int j=de[i]-len+1; j<l[i] && j<de[i]+len-1; ++j){
		st=link[h[i][j]-'a'][st];
		if (st==len)
		b[i]++;
	}
}

void din(void){
	d[1]=(s=="a" ? 1:0);
	d[2]=(s=="b" ? 1:0);
	
	for (int i=3; i<=n; ++i){
		d[i]=d[i-1]+d[i-2];
		
		if (i<=m){
			int j=fl[i-1]-len+1,st=0;
			if (j<0)
			j=0;	
			
			for (; j<fl[i] && j<fl[i-1]+len-1; ++j){
				st=link[f[i][j]-'a'][st];
				if (st==len)
				d[i]++;
			}

		}
		else
		d[i]+=b[(i-1)%2];
		
		if (d[i]>=mod)
		d[i]-=mod;
	}
	
	cout<<d[n]<<"\n";
	
}

int main()
{
	int t;
	pre();
	cin>>n>>t;
	while (t--){
		cin>>s;
		cmp();
		pre_calc();
		din();
	}
	return 0;
}