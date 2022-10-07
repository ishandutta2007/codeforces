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

const int maxn = 2e5;
const int inf = 1e9;

struct node{
    int a, b, x, id;
};


node a[maxn];

bool cmpX(node a, node b){
    return a.x < b.x;
}
bool cmpId(node a, node b){
    return a.id < b.id;
}

int main(){
   // freopen("in", "r", stdin);
  //  freopen("out", "w", stdout);
    int n, k, x, len; /// a b
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
    scanf("%d", &x);
    a[i].x = x;
    a[i].id = i;
    a[i].a = a[i].b = -1;
    }
    
    sort(a, a + n, cmpX);
    
    len = (n + 2) / 3;
    for(int i = 0; i < len; i++)
    a[i].a = 0, a[i].b = a[i].x;
    
    k = 0;
    for(int i = len; i < n; i += 2)
    a[i].b = k++;
    
    k = 0;
    for(int i = len + 1; i < n; i += 2)
    a[i].a = k++;
    
    
    for(int i = 0; i < n; i++){
    if (a[i].a == -1)
        a[i].a = a[i].x - a[i].b;
    
    if (a[i].b == -1)
        a[i].b = a[i].x - a[i].a;
    }
    
    sort(a, a + n, cmpId);
    printf("YES\n");
    for(int i = 0; i < n; i++)
    printf("%d ", a[i].a);
    printf("\n");
    for(int i = 0; i < n; i++)
    printf("%d ", a[i].b);
    printf("\n");
    ///debug
//     set < int > qq;
//     qq.clear();
//     int cnt = 0;
//     for(int i = 0; i < n; i++)   
//  if (qq.find(a[i].a) == qq.end())
//      qq.insert(a[i].a);
//  else
//      cnt++;
//  
//     epr("cnt1 %d\n", cnt);
//     assert(cnt <= len);
//     
//     qq.clear();
//     cnt = 0;
//     for(int i = 0; i < n; i++)   
//  if (qq.find(a[i].b) == qq.end())
//      qq.insert(a[i].b);
//  else
//      cnt++;
//     epr("cnt2 %d\n", cnt);
//     assert(cnt <= len);
    
    return 0;
}