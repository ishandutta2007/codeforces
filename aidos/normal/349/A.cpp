#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int main () {   
    int a = 0, b = 0, n, d[100500];
    cin >> n;
    for(int i = 0; i<n; i++){
    	cin >> d[i];
    }
    for(int i = 0; i<n; i++ ){
    	if(d[i] == 100){
    		if(b>0 && a > 0){
    			b--;
    			a--;
    		}
    		else if(a > 2){
    			a-=3;
    		}
    		else {
    			cout << "NO";
    			return 0;
    		}
    	}
    	else if(d[i] == 50){
    		if(a > 0){
    			a--;
    			b++;
    		}
    		else {
    			cout << "NO";
    			return 0;
    		}
    	}
    	else a++;
    }
    cout << "YES";
    return 0;
}