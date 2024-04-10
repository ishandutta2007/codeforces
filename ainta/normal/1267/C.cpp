#include<bits/stdc++.h>

using namespace std;
    
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define pb push_back
#define pli pair<long long,int>
    
#define Fi first
#define Se second
    
struct point {
    int a, c;
    bool operator <(const point &p)const {
        return c < p.c;
    }
};

vector<pii>Ans;
void Add(int a, int b) {
    Ans.push_back({ a,b });
}

bool OK(vector<point>w){
    if(w.empty())return true;
    sort(w.begin(),w.end());
    reverse(w.begin(),w.end());
    int i, n = w.size(), m = 0, o = 0, l = 0;
    for(i=0;i<w.size();i++){
        m+=w[i].c;
        if(w[i].c%2)o++;
        if(w[i].c==1)l++;
        if(w[i].c<=0)return false;
    }
    if(m%2==1)return false;
    m/=2;
    int c = m-n+1;
    if(c<0)return false;
    if(c>(n-1)/2)return false;
    if(n==2){
        Add(w[0].a,w[1].a);
        return true;
    }
    if(w[0].c==2 && w[n-1].c == 2){
        for(i=0;i<n;i++) Add(w[i].a,w[(i+1)%n].a);
        return true;
    }
    int b = max(o/2,l);
    if(c>(n-1-b)/2)return false;
    if(l){
        int u = w[n-1].a;
        for(i=0;i<n;i++){
            if(w[i].c%2==1 && w[i].c!=1){
                w[i].c--;
                Add(w[i].a,u);
                w.pop_back();
                OK(w);
                return true;
            }
        }
        Add(w[0].a, u);
        w[0].c--;
        w.pop_back();
        OK(w);
        return true;
    }
    int x = w[0].a, y = w[n-2].a, z = w[n-1].a;
    Add(x,y);Add(y,z);Add(z,x);
    w.pop_back();
    w.pop_back();
    w[0].c-=2;
    OK(w);
    return true;
}

int main() {
    int i, n;
    scanf("%d", &n);
    vector<point>w(n);
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i].c);
        w[i].a = i+1;
    }
    if (!OK(w)) {
        puts("-1");
        return 0;
    }

    printf("%d\n", Ans.size());
    for (auto &t : Ans) {
        printf("2 %d %d\n", t.first, t.second);
    }
}