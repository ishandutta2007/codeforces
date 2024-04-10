#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
//stdio contest templete
#include <iostream>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);(i)++)
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);(i)++)4
#ifdef _MSC_VER
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it,o.begin()); it != (o).end(); it ++)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
using namespace std;
typedef long long ll; typedef vector<int> vi; typedef pair<int,int> pii;

int main(){
    char s[250];
    gets(s);
    int n = strlen(s);
    bool b = false;
    int j = 0;
    rep(i, n){
        if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B'){
            i+=2;
            b = false;
        }else{
            if(!b&&j){
                putchar(' ');
            }
            putchar(s[i]);
            b = true;
            ++j;
        }
    }
    puts("");
    return 0;
}