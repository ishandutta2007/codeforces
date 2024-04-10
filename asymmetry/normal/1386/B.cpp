#include <bits/stdc++.h>

using namespace std;

struct frac
{
	long long x, y;
	void gen(long long a, long long b)
	{
		long long g=__gcd(a, b);
		x=a/g;
		y=b/g;
	}
};

struct punc
{
	frac x, y;
	void gen(int a, int b, int c)
	{
		x.gen(a, a+b+c);
		y.gen(b, a+b+c);
	}
};

bool operator == (frac p, frac q)
{
	return p.x==q.x && p.y==q.y;
}

bool operator != (frac p, frac q)
{
	return p.x*q.y!=q.x*p.y;
}

bool operator < (frac p, frac q)
{
	return p.x*q.y<q.x*p.y;
}

bool operator == (punc p, punc q)
{
	return p.x==q.x && p.y==q.y;
}

bool operator < (punc p, punc q)
{
	return p.x<q.x || (p.x==q.x && p.y<q.y);
}

bool operator != (punc p, punc q)
{
	return p.x!=q.x || p.y!=q.y;
}

struct line
{
	frac A, B;
	void gen(punc p, punc q)
	{
		if(p.x<q.x) swap(p, q);
		A.gen(p.x.x*q.x.y-q.x.x*p.x.y, p.x.y*q.x.y);
		B.gen(q.y.x*p.y.y-p.y.x*q.y.y, q.y.y*p.y.y);
		if(!A.x)
		{
			A={0, 1};
			B={1, 1};
			return;
		}
		if(!B.x)
		{
			A={1, 1};
			B={0, 1};
			return;
		}
		B.x*=A.y;
		B.y*=A.x;
		A={1, 1};
		if(B.y<0)
		{
			B.x*=-1;
			B.y*=-1;
		}
		long long g=__gcd(abs(B.x), B.y);
		B.x/=g;
		B.y/=g;
		if(B.y<0)
		{
			B.x*=-1;
			B.y*=-1;
		}
	}
};

bool operator < (line p, line q)
{
	return p.A<q.A || (p.A==q.A && p.B<q.B);
}

bool operator == (line p, line q)
{
	return p.A==q.A && p.B==q.B;
}

bool operator != (line p, line q)
{
	return p.A!=q.A || p.B!=q.B;
}

struct int128
{
	bool sig;
	long long w[4];
	void gen(long long x)
	{
		if(x<0) sig=1;
		else sig=0;
		w[0]=abs(x);
		for(int i=1; i<4; ++i) w[i]=0;
	}
};

int128 operator * (int128 p, int128 q)
{
	int128 ret;
	int l1=0, l2=0;
	for(int i=0; i<4; ++i)
	{
		if(p.w[i]) l1=i;
		if(q.w[i]) l2=i;
		ret.w[i]=0;
	}
	for(int i=0; i<=l1; ++i)
	{
		for(int j=0; j<=l2; ++j)
		{
			ret.w[i+j]+=p.w[i]*q.w[j];
		}
	}
	int x=min(2, l1+l2);
	for(int i=0; i<=x; ++i)
	{
		ret.w[i+1]+=ret.w[i]/(int)1e8;
		ret.w[i]%=(int)1e8;
	}
	ret.sig=p.sig^q.sig;
	return ret;
}

bool operator < (int128 p, int128 q)
{
	if(p.sig)
	{
		if(q.sig)
		{
			for(int i=3; i>=0; --i)
			{
				if(p.w[i]>q.w[i])
				{
					return true;
				}
				if(p.w[i]<q.w[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return true;
		}
	}
	else
	{
		if(q.sig)
		{
			return false;
		}
		else
		{
			for(int i=3; i>=0; --i)
			{
				if(p.w[i]<q.w[i])
				{
					return true;
				}
				if(p.w[i]>q.w[i])
				{
					return false;
				}
			}
			return false;
		}
	}
	return true;
}

int128 operator + (int128 p, int128 q)
{
	int128 ret;
	for(int i=0; i<4; ++i)
	{
		ret.w[i]=p.w[i]*(1-2*p.sig)+q.w[i]*(1-2*q.sig);
	}
	for(int i=0; i<3; ++i)
	{
		ret.w[i+1]+=ret.w[i]/(int)1e8;
		ret.w[i]%=(int)1e8;
	}
	for(int i=1; i<4; ++i)
	{
		if(ret.w[i-1]<0)
		{
			ret.w[i-1]+=1e8;
			--ret.w[i];
		}
	}
	ret.sig=0;
	if(ret.w[3]<0)
	{
		ret.sig=1;
		for(int i=0; i<4; ++i)
		{
			ret.w[i]=-ret.w[i];
		}
		for(int i=1; i<4; ++i)
		{
			if(ret.w[i-1]<0)
			{
				ret.w[i-1]+=1e8;
				--ret.w[i];
			}
		}
	}
	return ret;
}

bool operator == (int128 p, int128 q)
{
	if(p.sig!=q.sig)
	{
		for(int i=0; i<4; ++i)
		{
			if(p.w[i] || q.w[i]) return false;
		}
		return true;
	}
	for(int i=0; i<4; ++i)
	{
		if(p.w[i]!=q.w[i])
		{
			return false;
		}
	}
	return true;
}

int n, a, b, c, r1, r2, r3, r4, g, m, mm;
punc poic[100001];
line linc[100001];
int poz[100001];
int rem[100001];
int chan[100001];
int lins[100001][2];
char s[100001][2];
int sr[100001];
pair <line, int> sr2[100001];
set <pair <int, int> > S;
int128 f[100001][12];

void prep(int p)
{
	int128 a1, a3, b1, b3, c1, c3, d1, d3;
	a1.gen(poic[p].x.x);
	b1.gen(poic[p].x.y);
	c1.gen(poic[p].y.x);
	d1.gen(poic[p].y.y);
	a3.gen(poic[0].x.x);
	b3.gen(poic[0].x.y);
	c3.gen(poic[0].y.x);
	d3.gen(poic[0].y.y);
	f[p][0]=a1*d1*b3*d3;
	f[p][1]=b1*d1*b3*c3;
	f[p][2]=b1*c1*a3*d3;
	f[p][3]=b1*c1*b3*d3;
	f[p][4]=b1*d1*a3*d3;
	f[p][5]=a1*d1*b3*c3;
	f[p][6]=b1*c1;
	f[p][7]=a1*d1;
	f[p][8]=b1*d1;
	f[p][9]=a1*d1;
	f[p][10]=b1*c1;
	f[p][11]=b1*d1;
}

bool cmp(int p, int q)
{
	if(poic[p].x<poic[0].x && !(poic[q].x<poic[0].x))
	{
		return true;
	}
	if(!(poic[p].x<poic[0].x) && poic[q].x<poic[0].x)
	{
		return false;
	}
	return (f[p][0]*f[q][6])+(f[p][1]*f[q][7])+(f[p][2]*f[q][8])<(f[p][3]*f[q][9])+(f[p][4]*f[q][10])+(f[p][5]*f[q][11]);
	//~ return (a1*c2*b2*d3*b3*d1)+(a2*c3*b1*d2*b3*d1)+(a3*c1*b1*d2*b2*d3)<(a2*c1*b3*d2*b1*d3)+(a3*c2*b2*d1*b1*d3)+(a1*c3*b2*d1*b3*d2);
}

bool chck(int p, int q)
{
	int128 w1=(f[p][0]*f[q][6])+(f[p][1]*f[q][7])+(f[p][2]*f[q][8]);
	int128 w2=(f[p][3]*f[q][9])+(f[p][4]*f[q][10])+(f[p][5]*f[q][11]);
	if(w1==w2)
	{
		return false;
	}
	g=1;
	return w2<w1;
}

int main()
{
	scanf("%d%d%d", &a, &b, &c);
	poic[0].gen(a, b, c);
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s", s[i]);
		if(s[i][0]=='A')
		{
			scanf("%d%d%d", &a, &b, &c);
			++m;
			poic[m].gen(a, b, c);
			if(poic[m]!=poic[0]) 
			{
				linc[m].gen(poic[m], poic[0]);
				++mm;
				sr2[mm]={linc[m], m};
				sr[mm]=m;
				prep(m);
			}
		}
		else
		{
			scanf("%d", &rem[i]);
		}
	}
	sort(sr2+1, sr2+1+mm);
	sort(sr+1, sr+1+mm, cmp);
	sr2[0]=sr2[1];
	a=1;
	b=0;
	for(int i=1; i<=mm; ++i)
	{
		if(sr2[i-1].first!=sr2[i].first)
		{
			++a;
		}
		if(poic[sr2[i].second]<poic[0])
		{
			chan[sr2[i].second]=-a;
		}
		else
		{
			chan[sr2[i].second]=a;
		}
	}
	for(int i=1; i<=mm; ++i)
	{
		poz[sr[i]]=++b;
	}
	m=0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i][0]=='A')
		{
			++m;
			r1+=(poic[m]==poic[0]);
			if(poic[m]!=poic[0])
			{
				if(!lins[abs(chan[m])][0] || !lins[abs(chan[m])][1])
				{
					++lins[abs(chan[m])][(chan[m]>0)];
					r2+=(lins[abs(chan[m])][0] && lins[abs(chan[m])][1]);
				}
				else
				{
					++lins[abs(chan[m])][(chan[m]>0)];
				}
				if(S.size()>0)
				{
					auto y=S.lower_bound({poz[m], 0});
					int x;
					if(y==S.end())
					{
						x=(*S.begin()).second;
						r3+=chck(m, x);
						r4+=g;
					}
					else
					{
						x=(*y).second;
						r3+=chck(m, x);
						r4+=g;
					}
					int z;
					if(y==S.begin())
					{
						y=S.end();
						--y;
						z=(*y).second;
						r3+=chck(z, m);
						r4+=g;
					}
					else
					{
						--y;
						z=(*y).second;
						r3+=chck(z, m);
						r4+=g;
					}
					if(x!=z) r3-=chck(z, x);
					if(x!=z) r4-=g;
				}
				S.insert({poz[m], m});
			}
		}
		else
		{
			r1-=(poic[rem[i]]==poic[0]);
			if(poic[rem[i]]!=poic[0])
			{
				if(lins[abs(chan[rem[i]])][0] && lins[abs(chan[rem[i]])][1])
				{
					--lins[abs(chan[rem[i]])][(chan[rem[i]]>0)];
					r2-=(!lins[abs(chan[rem[i]])][0] || !lins[abs(chan[rem[i]])][1]);
				}
				else
				{
					--lins[abs(chan[rem[i]])][(chan[rem[i]]>0)];
				}
				S.erase({poz[rem[i]], rem[i]});
				if(S.size()>0)
				{
					auto y=S.lower_bound({poz[rem[i]], 0});
					int x;
					if(y==S.end())
					{
						x=(*S.begin()).second;
						r3-=chck(rem[i], x);
						r4-=g;
					}
					else
					{
						x=(*y).second;
						r3-=chck(rem[i], x);
						r4-=g;
					}
					int z;
					if(y==S.begin())
					{
						y=S.end();
						--y;
						z=(*y).second;
						r3-=chck(z, rem[i]);
						r4-=g;
					}
					else
					{
						--y;
						z=(*y).second;
						r3-=chck(z, rem[i]);
						r4-=g;
					}
					if(x!=z) r3+=chck(z, x);
					if(x!=z) r4+=g;
				}
			}
		}
		if(r1) printf("1\n");
		else if(r2) printf("2\n");
		else if(!r3 && S.size()>2 && r4) printf("3\n");
		else printf("0\n");
	}
	return 0;
}