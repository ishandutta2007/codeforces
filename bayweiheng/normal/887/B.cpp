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

int main() {
    int n,cur;
    cin>>n;
    bitset<10> cubes[3];
    for (int i=0;i<n;i++) {
        for(int j=0;j<6;j++) {
            cin>>cur;
            cubes[i][cur]=1;
        }
    }
    if (n==1) {
        int m=0;
        for(int i=1;i<10;i++) {
            if(cubes[0][i]) m=i;
            else break;
        }
        cout<<m<<endl;
    } else if (n==2) {
        int m=0;
        for(int i=1;i<10;i++) {
            if(cubes[0][i] || cubes[1][i]) m=i;
            else break;
        }
        if(m!=9) {
            cout<<m<<endl;
        } else {
            for(int i=10;i<100;i++) {
                int first=i/10;
                int second=i%10;
                if((cubes[0][first]&&cubes[1][second]) || (cubes[0][second]&&cubes[1][first])) m=i;
                else break;
            }
            cout<<m<<endl;
        }
    } else {
        int m=0;
        for(int i=1;i<10;i++) {
            if(cubes[0][i] || cubes[1][i] || cubes[2][i]) m=i;
            else break;
        }
        if(m!=9) {
            cout<<m<<endl;
        } else {
            for(int i=10;i<100;i++) {
                int first=i/10;
                int second=i%10;
                for(int j=0;j<2;j++) {
                    for(int k=j+1;k<3;k++) {
                        if((cubes[j][first]&&cubes[k][second]) || (cubes[j][second]&&cubes[k][first])) m=i;
                    }
                }
                if (m!=i) break;
            }
            cout<<m<<endl;
        }
    }
}