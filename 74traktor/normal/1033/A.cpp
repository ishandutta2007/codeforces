#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    int matr[n][n];

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            matr[i][j] = 0;
        }
    }

    int ax, ax1;
    cin >> ax >> ax1;
    ax -= 1;
    ax1 -= 1;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if ((i == ax) || (j == ax1) || (i + j == ax + ax1) || (i - j == ax - ax1)){
                matr[i][j] = 1;
            }
        }
    }

    /*for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout<<matr[i][j]<<" ";
        }
        cout<<""<<endl;
    }*/

    int bx, bx1;
    cin >> bx >> bx1;
    int cx, cx1;
    cin >> cx >> cx1;
    bx -= 1;
    bx1 -= 1;
    cx -= 1;
    cx1 -= 1;

    if (matr[bx][bx1] == 1 || matr[cx][cx1] == 1){
        cout<<"NO"<<endl;
        return 0;
    }
    else if ((bx < ax && cx < ax && bx1 < ax1 && cx1 < ax1)||(bx > ax && cx > ax && bx1 < ax1 && cx1 < ax1) || (bx < ax && cx < ax && bx1 > ax1 && cx1 > ax1) || (bx > ax && cx > ax && bx1 > ax1 && cx1 > ax1)){
        cout<<"YES"<<endl;
        return 0;
    }
    else{
        cout<<"NO"<<endl;
    }
}