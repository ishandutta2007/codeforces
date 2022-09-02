#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX

using namespace std;

using ll = long long;

#define mp make_pair


struct DSU {
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    string s;
    cin>>s;
    int cntopen = 0; int cntclosed = 0;
    for (int i = 0; i<n; i++) if (s[i]=='(') cntopen++; else cntclosed++;
    if (cntopen!=cntclosed) {cout<<-1; return 0;}

    int answer = 0;
    int lastneg = -1;
    int curbalance = 0;
    for (int i = 0; i<n; i++)
    {
        if (s[i]=='(') curbalance++; else curbalance--;
        if (lastneg==-1 && curbalance<0) lastneg = i;
        if (curbalance==0 && lastneg!=-1)
        {
            answer+=(i - lastneg + 1);
            lastneg = -1;
        }
    }
    cout<<answer;

}