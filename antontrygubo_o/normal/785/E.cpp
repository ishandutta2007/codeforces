#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 1e9 + 7;

void print(vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

int n, q;
int idx = 0;
int Q = 100;

vector<int> permut;

vector<pair<int, int>> query;

set<pair<int, int>> questions; //first border second value

map<pair<int, int>, int> answers; 

vector<int> fenw;

ll inversions = 0;

int sum (int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)   result += fenw[r];
    return result;
}

void inc (int i, int delta)
{
    for (; i <= n; i = (i | (i+1)))
    fenw[i] += delta;
}

int sum (int l, int r)
{
    return sum (r) - sum (l-1);
}

void solve()
{
    questions.clear();
    fenw.clear();
    fenw.resize(n+1);
    answers.clear();
    vector<int> perm1 = permut;
    for (int i = idx; i<min(idx+Q, q); i++)
    {
        int l = query[i].first;
        int r = query[i].second;
        swap(perm1[l], perm1[r]);
        questions.insert(make_pair(r-1, perm1[r]));
        questions.insert(make_pair(r-1, perm1[l]));
        questions.insert(make_pair(l, perm1[r]));
        questions.insert(make_pair(l, perm1[l]));
    }
    
    perm1 = permut;
    int cur = 0;
    for (auto it = questions.begin(); it!=questions.end(); it++)
    {
        while (cur+1<=it->first) {cur++; inc(perm1[cur], 1);}
        answers[*it] = sum(it->second);
        //cout<<it->first<<' '<<it->second<<" : "<<answers[*it]<<endl;
    }
    

    
    for (int i = idx; i<min(idx+Q, q); i++)
    {
        int l = query[i].first;
        int r = query[i].second;
        //cout<<endl<<endl; print(perm1);
        
    /*for (auto it = questions.begin(); it!=questions.end(); it++)
    {
        cout<<it->first<<' '<<it->second<<" : "<<answers[*it]<<endl;
    }*/
        
        if (l==r) {cout<<inversions<<endl; continue;}

        for (auto it = questions.begin(); it!=questions.end(); it++) if(l<=(it->first)&&(it->first)<r)
        {
            if (perm1[l]<=(it->second)) answers[*it]--;
            if (perm1[r]<=(it->second)) answers[*it]++;
        }
        
        if (perm1[l]<perm1[r])
        {
            inversions++;
            inversions+=2*(answers[make_pair(r-1, perm1[r])] - answers[make_pair(l, perm1[r])] - answers[make_pair(r-1, perm1[l])] + answers[make_pair(l, perm1[l])]);
        }
        else
        {
            inversions--;
            inversions+=2*(answers[make_pair(r-1, perm1[r])] - answers[make_pair(l, perm1[r])] - answers[make_pair(r-1, perm1[l])] + answers[make_pair(l, perm1[l])]);
        }
        cout<<inversions<<endl;
        swap(perm1[l], perm1[r]);
        
    }
    idx = idx+Q;
    permut = perm1;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>q;
    fenw.resize(n+1);
    permut.resize(n+1);
    query.resize(q);
    for (int i = 0; i<=n; i++) permut[i] = i;
    
    
    for (int i = 0; i<q; i++) {cin>>query[i].first>>query[i].second; if (query[i].first>query[i].second) swap(query[i].first, query[i].second);}
    
    while (idx<q) solve();
    
}