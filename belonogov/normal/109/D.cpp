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

const int maxn = 1e5 + 10;
const int inf = 1e9;

pair < int, int > a[maxn];
int b[maxn];
int c[maxn];
vector < pair < int, int > > answer;

bool check(int d){
    bool flag = 1;
    for (; d > 0; d /= 10)
        flag = flag && (d % 10 == 7 || d % 10 == 4);
    return flag;    
}


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, pos = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &b[i]);
        a[i].fr = b[i];
        a[i].sc = i;        
    }
    
    
    sort(a, a + n);
    for (int i = 0; pos == -1 && i < n; i++){
        if (check(a[i].fr))
            pos = i;
    }
    epr("pos %d\n", pos);
    if (pos == -1){
        bool flag = 1;
        for (int i = 1; i < n; i++)
            flag = flag && b[i - 1] <= b[i];
        printf("%d\n", (int)flag - 1);      
        return 0;       
    }
    
    for (int i = 0; i < n; i++){
        c[a[i].sc] = i;     
    }
//  epr("c : ");
//  for (int i = 0; i < n; i++)
//      epr("%d ", c[i]);
//  epr("\n");
//  epr("a : ");
//  for (int i = 0; i < n; i++)
//      epr("%d ", a[i].sc);
//  epr("\n");
//  
    pos = a[pos].sc;
    epr("pos %d\n", pos);
    for (int i = 0; i < n; i++){
//      epr("\nNew step\n");
        
        if (pos != i){
//          printf("%d %d\n", pos, i);
            answer.pb(mp(pos, i));
            
            swap(c[pos], c[i]);
            swap(a[c[pos]].sc, a[c[i]].sc);
            pos = i;
        }   

        if (pos != a[i].sc){
//          printf("%d %d\n", pos, a[i].sc);
            answer.pb(mp(pos, a[i].sc));
            swap(c[i], c[a[i].sc]);
            pos = a[i].sc;              
            swap(a[c[i]].sc, a[c[a[i].sc]].sc);
        }
//      epr("pos %d\n", pos);
//      epr("c : ");
//      for (int j = 0; j < n; j++)
//          epr("%d ", c[j]);
//      epr("\n");
//      epr("a : ");
//      for (int j = 0; j < n; j++)
//          epr("%d ", a[j].sc);
//      epr("\n");
        
    }
    printf("%d\n", (int)answer.size());
    for (int i = 0; i < (int)answer.size(); i++)
        printf("%d %d\n", answer[i].fr + 1, answer[i].sc + 1);
    for (int i = 0; i < (int)answer.size(); i++){
        assert(check(b[answer[i].fr]) || check(b[answer[i].sc]));
        swap(b[answer[i].fr], b[answer[i].sc]);
    }
    for (int i = 0; i < n - 1; i++)
        assert (b[i] <= b[i + 1]);
//  for (int i = 0; i < n; i++)
//      epr("%d%c", b[i], " \n"[i == n - 1]);
    
    return 0;
}