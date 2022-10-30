#include<bits/stdc++.h>
#define pi 3.141592653589793238
using namespace std;
struct com{
	double a,b;
};
com operator *(com &a,com &b)
{
	return (com){a.a*b.a-a.b*b.b,a.a*b.b+b.a*a.b};
}
com operator +(com &a,com &b)
{
	return (com){a.a+b.a,a.b+b.b};
}
com operator -(com &a,com &b)
{
	return (com){a.a-b.a,a.b-b.b};
}
char c[150005],s[150005];
int i,f[150005][10],n,m,lim,L,p[150005],j,ans;
int R[500005];
com a[500005], b[500005];
void fft(com *a, int f,int n) {
    for (int i = 0; i < n; i++)
        if (i < R[i])
            swap(a[i], a[R[i]]);
    for (int i = 1; i < n; i <<= 1) {
        com wn=(com){cos(pi / i), f * sin(pi / i)};
        for (int p = i << 1, j = 0; j < n; j += p) {
            com w=(com){1, 0};
            for (int k = 0; k < i; k++, w = w * wn) {
                com x = a[j + k], y = w * a[j + k + i];
                a[j + k] = x + y;
                a[j + k + i] = x - y;
            }
        }
    }
}
int Find(int x,int i)
{
	if(f[x][i]==0)
		return i;
	return f[x][i]=Find(x,f[x][i]);
}
void merge(int e,int u,int v)
{
	int x=Find(e,u),y=Find(e,v);
	if(x!=y)
		f[e][x]=y;
}
int main()
{
	scanf("%s",c);
	n=strlen(c);
	scanf("%s",s);
	m=strlen(s);
	for(i=0;i*2<m;++i)
		swap(s[i],s[m-i-1]);
	for(int ta=0;ta<6;++ta)
		for(int tb=0;tb<6;++tb)
			if(ta!=tb)
			{
				memset(a,0,sizeof(a));
				memset(b,0,sizeof(b));
				memset(p,0,sizeof(p));
				for(i=0;i<n;++i)
					if(c[i]=='a'+ta)
						a[i]=(com){1,0};
					else
						a[i]=(com){0,0};
				for(i=0;i<m;++i)
					if(s[i]=='a'+tb)
						b[i]=(com){1,0};
					else
						b[i]=(com){0,0};
				for (L = 0 , lim = 1; lim <= n + m; lim <<= 1) ++L;
    			for (int i = 0; i < lim; i++) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
    			fft(a,1,lim);
    			fft(b,1,lim);
    			for(i=0;i<lim;++i)
    				a[i]=a[i] * b[i];
    			fft(a,-1,lim);
    			for(i=m;i<=n;++i)
					if((int)(a[i-1].a/n+0.5))
						merge(i-m,ta+1,tb+1);
			}
	for(i=0;i<=n-m;++i)
	{
		ans=0;
		for(j=1;j<=6;++j)
			if(Find(i,j)==j)
				++ans;
		printf("%d ",6-ans);
	}
}