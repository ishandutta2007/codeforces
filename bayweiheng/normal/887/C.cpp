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



bool check_faces(vi &v) {
    if (v[1]!=v[2] || v[1]!=v[3] || v[1]!=v[4]) return 0;
    if (v[5]!=v[6] || v[5]!=v[7] || v[5]!=v[8]) return 0;
    if (v[9]!=v[10] || v[9]!=v[11] || v[9]!=v[12]) return 0;
    if (v[13]!=v[14] || v[13]!=v[15] || v[13]!=v[16]) return 0;
    if (v[17]!=v[18] || v[17]!=v[19] || v[17]!=v[20]) return 0;
    if (v[21]!=v[22] || v[21]!=v[23] || v[21]!=v[24]) return 0;
    return 1;
}

void rotleftdown(vi &v) {
    int t1=v[1];
    int t2=v[3];
    v[1]=v[5];
    v[3]=v[7];
    v[5]=v[9];
    v[7]=v[11];
    v[9]=v[24];
    v[11]=v[22];
    v[24]=t1;
    v[22]=t2;
}


void rotleftup(vi &v) {
    for(int i=0;i<3;i++) rotleftdown(v);
}

void rottopleft(vi &v) {
    int t1=v[1];
    int t2=v[2];
    v[1]=v[18];
    v[2]=v[20];
    v[18]=v[12];
    v[20]=v[11];
    v[12]=v[15];
    v[11]=v[13];
    v[15]=t1;
    v[13]=t2;
}

void rottopright(vi &v) {
    for(int i=0;i<3;i++) rottopleft(v);
}

void rotfrontleft(vi &v) {
    int t1=v[15];
    int t2=v[16];
    v[15]=v[7];
    v[16]=v[8];
    v[7]=v[19];
    v[8]=v[20];
    v[19]=v[23];
    v[20]=v[24];
    v[23]=t1;
    v[24]=t2;
}

void rotfrontright(vi &v) {
    for(int i=0;i<3;i++) rotfrontleft(v);
}

int main() {
    vi v;
    v.push_back(100);
    int cur;
    for(int i=0;i<24;i++) {
        cin>>cur;
        v.push_back(cur);
    }
    bool can=0;
    rotfrontright(v);
    can=can||check_faces(v);
    rotfrontleft(v);
    rotfrontleft(v);
    can=can||check_faces(v);
    rotfrontright(v);
    rottopright(v);
    can=can||check_faces(v);
    rottopleft(v);
    rottopleft(v);
    can=can||check_faces(v);
    rottopright(v);
    rotleftdown(v);
    can=can||check_faces(v);
    rotleftup(v);
    rotleftup(v);
    can=can||check_faces(v);
    rotleftdown(v);
    if (can) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}