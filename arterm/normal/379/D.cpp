#include <iostream>
#include <string>

using namespace std;

#define M 55

bool pos(bool first, bool last, int c, int n){//first C, last A
	if (n==1)
		return (!first || !last) && c==0;
		
	if (n==2){
		if (c==1)
		return !first && !last;
		if (c>1)
		return 0;
		return 1;
	}
	
	if (first)
	--n;
	
	if (last)
	--n;
	
	return n/2>=c;
}

string tot(bool first, bool last, int c, int n){//first C, last A
	if (n==1){
		if (first)
		return "C";
		if (last)
		return "A";
		return "B";
	}
		
	if (n==2){
		if (c==1)
		return "AC";
		string ans(2,'B');
		ans[0]=first ? 'C':'B';
		ans[1]=last ?  'A':'B';
	}
	
	string ans(n,'B');
	
	int l=0,r=n-1;
	
	if (first)
	ans[l++]='C';
	
	if (last)
	ans[r--]='A';
	
	for (int i=0; i<c; ++i){
		ans[l]='A';
		ans[l+1]='C';
		l+=2;
	}
	
	return ans;
}

int n,m,k,x;
int a[M];
bool f[M],l[M];

bool good(){
	for (int i=3; i<=k; ++i){
		a[i]=a[i-2]+a[i-1]+(f[i-1] && l[i-2] ? 1:0);
		f[i]=f[i-2];
		l[i]=l[i-1];
		if (a[i]>x)
		return 0;
	}
	
	return a[k]==x;
}

void kill(void){
	for (int i=0; 2*i<=n; ++i)
	for (int j=0; 2*j<=m; ++j)
	for (int f1=0; f1<2; ++f1)
	for (int f2=0; f2<2; ++f2)
	for (int l1=0; l1<2; ++l1)
	for (int l2=0; l2<2; ++l2){
		a[1]=i;
		a[2]=j;
		f[1]=f1;
		f[2]=f2;
		l[1]=l1;
		l[2]=l2;
		if (pos(f1,l1,i,n) && pos(f2,l2,j,m) && good()){
			cout<<tot(f1,l1,i,n)<<"\n";
			cout<<tot(f2,l2,j,m)<<"\n";
			return;
		}
	}
	cout<<"Happy new year!\n";
}

int main()
{
	cin>>k>>x>>n>>m;
	kill();
	return 0;
}