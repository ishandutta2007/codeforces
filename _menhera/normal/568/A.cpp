#include<cstdio>
#define MAXN 1179888
bool prime[MAXN];
bool ispal[MAXN];
int pi[MAXN];
int pal[MAXN];
bool isPrime(int a)
{
	if(a<2) return false;
	if(a==2) return true;
	if(a%2==0) return false;
	for(int i=3;i*i<=a;i+=2)
		if(a%i==0) return false;
	return true;
}
bool isPal(int a)
{
	int c=0,aa=a;
	while(aa)
	{
		c*=10;
		c+=aa%10;
		aa/=10;
	}
	return a==c;
}
int main()
{
	int P,Q;
	scanf("%d%d",&P,&Q);
	// pi(n) <=  P/ Q * rub(N)
	//pi(N)*Q <= P rub ( N)
	int res=-1;
	for(int i=1;i<MAXN;i++)
	{
		prime[i]=isPrime(i);
		pi[i]=pi[i-1]+prime[i];
		ispal[i]=isPal(i);
		pal[i]=pal[i-1]+ispal[i];
		//if(i<40) printf("%d %d\n",pi[i],pal[i]);
		if (pi[i]*Q<=P*pal[i]) res=i;
	}
	if(~res) 
		printf("%d",res);
	else
		puts("Palindromic tree is better than splay tree");
	return 0;
}