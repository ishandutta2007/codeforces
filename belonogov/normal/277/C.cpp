#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 

const int maxn = 2e5 + 10;
const int inf = (int)1e9;

struct seg{
    int x1, y1, x2, y2;
    seg(){}
    seg(int x1, int y1, int x2, int y2): x1(min(x1, x2)), y1(min(y1, y2)), x2(max(x1, x2)), y2(max(y1, y2)) {};
//     seg(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {};
    
    void Swap(){
        swap(x1, y1);
        swap(x2, y2);
    }
    void print(){
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
};

seg a[maxn];
seg b[maxn];
pair < int, int > c[maxn];
vector < int > e[2];


bool cmpX(seg a, seg b){
    return a.x1 < b.x1;
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, k, r, x1, x2, y1, y2, need, p, cur, cur1, free, last;
    int sum, cnt, cnt2;
    int ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; i++){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        a[i] = seg(x1, y1, x2, y2);
    }
    
    for(int t = 0; t < 2; t++){
        cur = 0;
        for(int i = 0; i < k; i++)
            if (a[i].x1 == a[i].x2)
    b[cur++] = a[i];
        sort(b, b + cur, cmpX);
        cnt2 = 0;
        for(int l = 0; l < cur;){
            cnt2++;
            cur1 = 0;
            for(r = l; r < cur && b[l].x1 == b[r].x1; r++){
    c[cur1++] = mp(b[r].y1, 1);
    c[cur1++] = mp(b[r].y2, -1);
//  b[r].print();
            }
//             epr("\n");
            sort(c, c + cur1);
            
            /*     for(int i = 0; i < cur1; i++)
    epr("%d %d\n", c[i].fr, c[i].sc);
            epr("\n");
       */     sum = cnt = p = 0;
            for(int i = 0; i < cur1; i++){
    if (cnt == 0) sum += c[i].fr - p;
    cnt += c[i].sc;
    p = c[i].fr;    
            }
            sum += m - p;
            ans ^= sum;
            e[t].pb(sum);
            l = r;
        }
//         epr("cnt2 %d\n", cnt2);

        if ((n - 1 - cnt2) % 2 == 1)
            ans ^= m, e[t].pb(m);
        
        
        for(int i = 0; i < k; i++)
            a[i].Swap();
        swap(n, m);
    }/*
    for(int t = 0; t < 2; t++){
        for(int i = 0; i < (int)e[t].size(); i++)
            epr("%d ", e[t][i]);
        epr("\n");
    }
    epr("ans %d\n", ans);
    */
    if (ans == 0){
        printf("SECOND\n");
        return 0;
    }
    printf("FIRST\n");
    /// try to step
   
    
    for(int t = 0; t < 2; t++){
        cur = 0;
        for(int i = 0; i < k; i++)
            if (a[i].x1 == a[i].x2)
    b[cur++] = a[i];
        sort(b, b + cur, cmpX);
        last = 0;
        free = -1;
        cnt2 = 0;
        for(int l = 0; l < cur; cnt2++){
            if (b[l].x1 - 1 > last) free = last + 1;
            last = b[l].x1;
//             epr("last %d\n", last);
            cur1 = 0;
           
            for(r = l; r < cur && b[l].x1 == b[r].x1; r++){
    c[cur1++] = mp(b[r].y1, 1);
    c[cur1++] = mp(b[r].y2, -1);
            }
            sort(c, c + cur1);
           
            sum = cnt = p = 0;
            if((ans ^ e[t][cnt2]) < e[t][cnt2]){
    need = e[t][cnt2] - (ans ^ e[t][cnt2]);
//  epr("need %d\n", need);
    for(int i = 0; i < cur1; i++){
        if (cnt == 0) sum += c[i].fr - p;
        cnt += c[i].sc;
        if (sum >= need){
            seg sg = seg(b[l].x1, 0, b[l].x1, c[i].fr - (sum - need));
            if (t) sg.Swap();
            sg.print();
            return 0;
        }
        p = c[i].fr;    
    }
    sum += m - p;
//  epr("sum %d\n", sum);
    seg sg = seg(b[l].x1, 0, b[l].x1, m - (sum - need));
    if (t) sg.Swap();
    sg.print();
    return 0;
    
            }
            l = r;
        }
//         epr("last %d\n", last);
        if (last < n - 1) free = n - 1;
//         epr("cnt2 %d\n", cnt2);
        if ((n - 1 - cnt2) % 2 == 1 && (ans ^ m) < m){
            assert(free != -1);
//             epr("1:\n");
            seg sg = seg(free, 0, free, m - (ans ^ m));
            if (t) sg.Swap();
            sg.print();
            return 0;
            
        }
          
        
        for(int i = 0; i < k; i++)
            a[i].Swap();
        swap(n, m);
    }
   
   
    assert(false);

    return 0;
}



//     for(int t = 0; t < 2; t++){
//         cur = 0;
//         for(int i = 0; i < k; i++)
//             if (a[i].x1 == a[i].x2)
//  b[cur++] = a[i];
//         sort(b, b + cur, cmpX);
//         cnt2 = 0;
//         last = -1;
//         free = -1;
//         cur1 = 0;
//         for(int l = 0; l < k;){
//             if (a[l].x1 > last + 1) free = a[l].x1 - 1;
//             last = a[l].x1;
//             cnt2++;
//             for(r = l; r < k && a[l].x1 == a[r].x1; r++){
//  c[cur1++] = mp(a[r].y1, 1);
//  c[cur1++] = mp(a[r].y2, -1);
//             }
//             if((ans ^ e[t][cnt2]) >= e[t][cnt2]) continue;
//             
//             need = e[t][cnt2] - (e[t][cnt2] ^ ans);
//             sum = cnt = p = 0;
//             for(int i = 0; i < cur1; i++){
//  if (cnt == 0) sum += c[i].fr - p;
//  if (sum >= need){
//      seg sg = seg(a[l].x1, 0, a[l].x1, c[i].fr - (sum - need));
//      if (t) sg.Swap();
//      sg.print();
//      return 0;
//  }
//  cnt += c[i].sc;
//  p = c[i].fr;    
//             }
//             sum += m - p;
//             l = r;
//         }
//         if (last < n - 1) free = n - 1;
//         if ((n - cnt2) % 2 == 1 && (ans ^ m) < m){
//             assert(free != -1);
//             seg sg = seg(free, 0, free, m - (ans ^ m));
//             if (t) sg.Swap();
//             sg.print();
//             return 0;
//         }
//         
//         
//         for(int i = 0; i < k; i++)
//             a[i].Swap();
//         swap(n, m);
//     }