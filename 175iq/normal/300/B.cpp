#include <bits/stdc++.h>
using namespace std;

//Utility functions
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define clr(arr) memset((arr), 0, sizeof(arr))
#define setval(arr,value) memset(arr,value,sizeof(arr)) //set elements of array to some value
#define foreach(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) //traverse an STL data structure
#define all(c) (c).begin(),(c).end() //handy for function like "sort()"
#define found(c,value) ((c).find(value) != (c).end()) 
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end()) 
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } //sort array of objects(structs)

//Constants
#define EPS 1e-8
#define PI 2*acos(0.0)
#define INF 0x3f3f3f3f
#define MOD 1e9+7

//Printing
#define coutA(a,L,R) FE(i,L,R) cout<<a[i]<<(i==R?'\n':' ')
#define coutV(a) coutA(a,0,a.size()-1)

//Checking bound
#define IN(i,l,r)   (l<i&&i<r) 
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r)  (l<=i&&i<r)
#define INR(i,l,r)  (l<i&&i<=r)

//For loops
#define F(i,a,b) 	for(int i=a; i<b; i++)
#define FE(i,a,b)   for(int i=a; i<=b; i++)
#define FR(i,a,b)   for(int i=b; i>a; i--)
#define FRE(i,a,b)  for(int i=b; i>=a; i--)

//For debug
struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;	
#define debug(args...) do {cerr << #args << ": "; dbg,args; cerr << endl;} while(0)
#define debugv(vec) FE(i,0,vec.sz-1) cerr<<vec[i]<<(i==vec.sz-1?'\n':' ') 

//Definitions
#define vi vector<int>  
#define vvi vector<vector<int> > 
#define viwv(vecname, N, value) vector<int> vecname(N, value) 
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP 
#define vvig(vecname, N) vector<vector<int> > vecname(N) //For Graph 

//#define pair<int,int> ii 
#define long long int ll 

//Directions 
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

viwv(mark, 50, 0);
vvig(g, 50);

void dfs(int i, int& size, vi &cc)
{
	mark[i] = 1;
	size++;	
	cc.pb(i);
	for(auto x : g[i])
	{
		if(!mark[x])
		{
			dfs(x, size, cc);
		}
	}
	return;
}

int main()
{
	int n,m;
	cin>>n>>m;

	int a,b;	
	F(i,0,m)	
	{		
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	int ncc = 0;
	int size = 0;
	
	vi cc;
	vvi vec1;
	vvi vec2;
	vvi vec3;
	
	FE(i,1,n)
	{
	    int before = mark[i];
		if(!mark[i])
		{
			size = 0;
			dfs(i,size,cc);
		}
		ncc++;
		int after = mark[i];
		if(!before && after)
		{
    		if(size>3)
    		{
    			cout<<-1;
    			return 0; 
    		}
    		else if(size == 1)
    		{
    			vec1.pb(cc);
    			cc.clear();
    		}
    		else if(size == 2)
    		{
    			vec2.pb(cc);
    			cc.clear();
    		}
    		else if(size == 3)
    		{
    			vec3.pb(cc);
    			cc.clear();
    		}
		}
	}
    debug(vec1.sz, vec2.sz, vec3.sz);

	if(vec1.sz<vec2.sz)
	{
		cout<<-1;       
		return 0; 		
	}
	
	int markx = 0;
	if(!vec2.sz && vec1.sz && !(vec1.sz%3))
	{
	    int count = 0;
	    F(i,0,vec1.sz)
	    {
	        count++;
	        cout<<vec1[i][0]<<" ";
	        if(!(count%3))
	        {
	            cout<<endl;
	        }
	    }
	    markx = 1;
	}
	debug(markx);
	if(markx)
	{
    	int svec3 = vec3.sz;
    	F(i,0,svec3)
    	{
    	    F(j,0,3)
    	    {
    	        cout<<vec3[i][j]<<" ";
    	    }
    	    cout<<endl;
    	}
    	return 0;	    
	}
	if(!vec2.sz && vec1.sz && (vec1.sz%3))
	{
	    cout<<"-1";
	    return 0;	    
	}
	
	int svec1 = vec1.sz;
	int svec2 = vec2.sz;
	if((svec2-svec1)%3)
	{
	    cout<<"-1";
	    return 0;	    
	}
	F(i, 0, svec2)
	{
		F(j, 0, 2)
		{
			cout<<vec2[i][j]<<" ";
		}
        cout<<vec1[i][0]<<" "<<endl;
	}
	int coun = 0 ; 
	F(j, svec2, svec1)
	{
	    cout<<vec1[j][0]<<" ";
	    coun++;
	    if(coun%3)
	    {
	        cout<<endl;
	    }
	}
	
	int svec3 = vec3.sz;
	F(i,0,svec3)
	{
	    F(j,0,3)
	    {
	        cout<<vec3[i][j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}