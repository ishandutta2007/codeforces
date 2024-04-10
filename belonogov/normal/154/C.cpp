#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e6 + 2;
const long long p = 1e9 + 7;

struct node{
    int x;
    node * next;
};

node * head[maxn];
long long b[maxn];
long long hash[maxn];
long long step[maxn];


void add(int x, int y){
    node * q = new node;
    q->x = y;
    q->next = head[x];
    head[x] = q;
}

int main()
{
     int n, m, i, x, y, uk, j;
    long long cnt = 0, kol;
    node * d;
    cin >> n >> m;
    memset(head, NULL, sizeof head);
    step[0] = 1;
    for (i = 1; i < n; i++)
        step[i] = step[i - 1] * p;
    for (i = 0; i < m; i++){
        scanf("%d%d", &x, &y);
     //   x--;                ////  
      //  y--;
        add(x, y);
        add(y, x);
    }

    /////////////111
    for (i = 1; i <= n; i++){
        uk = 0;
        for (d = head[i]; d != NULL; d = d->next){
            b[uk++] = d->x;
        }
        sort(b, b + uk);
        for (j = 0; j < uk; j++)
            hash[i - 1] += b[j] * step[j];
    }
    sort(hash, hash + n);

    kol = 1;
    for (i = 1; i < n; i++){
        if (hash[i - 1] == hash[i])
            kol++;
        else{
            cnt += kol * (kol - 1) / 2;
            kol = 1;
        }
    }
    cnt += kol * (kol - 1) / 2;

    memset(hash, 0, sizeof hash);
///////////////////////////////222
    for (i = 1; i <= n; i++){
        uk = 0;
        for (d = head[i]; d != NULL; d = d->next){
            b[uk++] = d->x;
        }
        b[uk++] = i;
        sort(b, b + uk);
        for (j = 0; j < uk; j++)
            hash[i - 1] += b[j] * step[j];
    }
    sort(hash, hash + n);

    kol = 1;
    for (i = 1; i < n; i++){
        if (hash[i - 1] == hash[i])
            kol++;
        else{
            cnt += kol * (kol - 1) / 2;
            kol = 1;
        }
    }
    cnt += kol * (kol - 1) / 2;


    cout << cnt;




    return 0;
}