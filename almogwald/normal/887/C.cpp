// Example program
#include <iostream>
#include <string>

using namespace std;
int main() {
    int sol;
    int a[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int s1[]={0,2,3,4,1,6,19,8,13,10,11,12,9,14,7,16,21,18,23,20,5,22,15,24,17};
    int s2[]={0,2,3,4,1,6,15,8,17,10,11,12,9,14,23,16,5,18,7,20,21,22,19,24,13};
    int s3[]={0,3,4,6,22,7,8,10,1,11,12,21,5,14,15,16,13,18,19,20,17,23,24,9,2};
    int s4[]={0,3,4,21,5,7,8,2,8,11,12,6,22,14,15,16,13,18,19,20,17,23,24,1,10};
    int s5[]={0,2,17,4,15,6,7,8,5,18,9,14,11,15,16,4,11,19,20,1,10,22,23,24,21};
    int s6[]={0,2,14,4,18,6,7,8,5,15,9,19,11,15,16,9,1,19,20,11,3,22,23,24,21};
    for(int i=1;i<25;i++){
        cin >> a[i];
    }
    sol = 1;
    for (int i=1;i<25;i++){
        if (a[i] != a[s1[i]]) {
            sol = 0;
        }
    }
    if (sol) {
          cout << "YES" << endl;
        return 0;
    }
    sol = 1;
    for (int i=1;i<25;i++){
        if (a[i] != a[s2[i]]) {
            sol = 0;
        }
    }
    if (sol) {
          cout << "YES" << endl;
        return 0;
    }
    sol = 1;
    for (int i=1;i<25;i++){
        if (a[i] != a[s3[i]]) {
            sol = 0;
        }
    }
    if (sol) {
          cout << "YES" << endl;
        return 0;
    }
    sol = 1;
    for (int i=1;i<25;i++){
        if (a[i] != a[s4[i]]) {
            sol = 0;
        }
    }
    if (sol) {
          cout << "YES" << endl;
        return 0;
    }
    sol = 1;
    for (int i=1;i<25;i++){
        if (a[i] != a[s5[i]]) {
            sol = 0;
        }
    }
    if (sol) {
          cout << "YES" << endl;
        return 0;
    }
    sol = 1;
    for (int i=1;i<25;i++){
        if (a[i] != a[s6[i]]) {
            sol = 0;
        }
    }
    if (sol) {
          cout << "YES" << endl;
        return 0;
    }
    
    cout << "NO" << endl;

}