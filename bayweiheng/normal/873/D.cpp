#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <cstring>
#include <queue>
#include <bitset>
#include <set>
#include <stack>
#include <complex>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

int maxk=0;
int k;
vi v;
int len;

void test(int s,int e) {
    //printf("testing %d %d\n",s,e);
    maxk++;
    if (s==e||s+1==e) return;
    int mid=(s+e)/2;
    test(s,mid);
    test(mid,e);
}

void shuffle(int s,int e) {
    if (k==1) return;
    if (s==e||s+1==e) return;
    //printf("shuffling %d %d\n",s,e);
    k-=2;
    int mid=(s+e)/2;
    len=e-s;
    vi temp;
    int st=e-mid+s;
    for(int i=st;i<e;i++) temp.push_back(v[i]);
    for(int i=s;i<st;i++) temp.push_back(v[i]);
    //for (int i:temp) cout<<i;
    //cout<<endl;
    for(int i=0;i<len;i++) v[i+s]=temp[i];
    shuffle(s,mid);
    shuffle(mid,e);
}

int main() {
    int n;
    cin>>n>>k;

    for(int i=1;i<=n;i++) {
        v.push_back(i);
    }
    test(0,n);
    //cout<<maxk<<endl<<endl;
    if (k%2==0||k>maxk) cout<<-1<<endl;
    else {
        shuffle(0,n);
        cout<<v[0];
        for(int i=1;i<n;i++) {
            printf(" %d",v[i]);
        }
    }
}