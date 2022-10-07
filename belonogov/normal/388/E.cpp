#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 2000;
const int inf = 1e9;
const long double eps7 = 1e-7;
const long double eps13 = 1e-13;


struct pnt{
    long double x, y;
    pnt(){}
    pnt(long double x, long double y): x(x), y(y){}
    pnt operator - (pnt A){
        return pnt(x - A.x, y - A.y);   
    }
    pnt operator + (pnt A){
        return pnt(x + A.x, y + A.y);
    }
    long double operator * (pnt a){
        return x * a.y - y * a.x;       
    }   
    long double operator % (pnt a){
		return x * a.x + y * a.y;
	}
    pnt operator / (long double k){
        return pnt(x / k, y / k);       
    }
    pnt operator * (long double k){
        return pnt(x * k, y * k);       
    }
    long double len(){
        return sqrt(x * x + y * y);
    }
    long double len2(){
        return x * x + y * y;           
    }
    void read(){
        double x1, y1;
        scanf("%lf%lf", &x1, &y1);
        x = x1;
        y = y1;
    }
    void Epr(){
        cerr.precision(4);
        cerr << "x y: " << fixed << x << " " << y << endl;
        
    }
};

struct Line{
    long double a, b, c;
    Line(){}
    Line(pnt p1, pnt p2){
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = - a * p1.x - b * p1.y;      
    }
    long double dist(pnt p){
        return (a * p.x + b * p.y + c) / sqrt(a * a + b * b);       
    }
    pnt operator * (Line l){
        return pnt((l.c * b - c * l.b) / (a * l.b - l.a * b), (l.c * a - c * l.a) / (b * l.a - l.b * a));       
    }
};

Line ttt(pnt p, pnt v){
	Line l;
	l.a = -v.y;
	l.b = v.x;
	l.c = - l.a * p.x - l.b * p.y;      
	return l;		
}


pnt p[maxn];
pnt v[maxn]; 
pnt vNew[maxn];

bool cmp2(pair < pnt, long double > a, pair < pnt, long double > b){
    return (a.fr * b.fr) > eps7 || (abs(a.fr * b.fr) < eps7 && a.sc < b.sc);      
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
	int n, t1, t2, ans = 1;
    pnt A, B, p1, p2, v1, V, P;
    Line l;
    long double t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &t1);
        p1.read();
        scanf("%d", &t2);
        p2.read();
        v1 = (p2 - p1) / (t2 - t1);
        p[i] = p1 - v1 * t1;
        v[i] = v1;
    }
    for (int i = 0; i < n; i++){
        V = v[i];
        for (int j = 0; j < n; j++)
            vNew[j] = v[j] - V;
		vector < long double > c;
        vector < pair < pnt, long double >  > d;
        for (int j = 0; j < n; j++)
            if (vNew[j].len2() > eps13){
				l = ttt(p[j], vNew[j]);
                if (abs(l.dist(p[i])) < eps7){
					t = (p[i] - p[j]).len() / (vNew[j].len());
					if (vNew[j] % (p[i] - p[j]) > 0)
						c.pb(t);
					else
						c.pb(-t);
                    /// second
         
					P = vNew[j];
					P = P / P.len();
					if (P.y < 0 || (P.y == 0 && P.x > 0))
						P = P * -1;
					d.pb(mp(P, P % vNew[j]));
					
        }   
                
                
            }
		sort(c.begin(), c.end());
        for (int j = 0; j < (int)c.size(); ){
            int k = j;
            for (; j < (int)c.size() && abs(c[j] - c[k]) < eps7; j++);               
            ans = max(ans, j - k + 1);              
        }
        sort(d.begin(), d.end(), cmp2);
		int t = d.size();
        for (int j = 0; j < t; ){
           
			int k = j;
            int cntM = 0;
            j++;
			for (; j < t && abs(d[j].fr * d[k].fr) < eps7; j++)
                if (abs(d[j].sc - d[j - 1].sc) < eps13)
                    cntM++;
            ans = max(ans, j - k + 1 - cntM);               
        }

        
    }
    cout << ans << endl;
 
    return 0;
}