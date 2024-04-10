#include <math.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int solve(int a[], int n);
void swap(int a[], int n, int i);

int main () {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int a[n];
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    cout << solve(a, n) << endl;
  }
}

int solve(int a[], int n) {
  int iters = 0;
  while (1) {
    bool sorted = true;
    for (int i = 0; i < n; i++) {
      if (a[i] != i+1) {
        sorted = false;
        break;
      }
    }
    if (sorted) return iters;
    iters += 1;
    swap(a, n, iters);
  }
  return iters;
} 
void swap(int a[], int n, int s) {
  for (int i = 1 - (s&1); i < n-1; i += 2){
    if (a[i] > a[i+1]) {
      int temp = a[i];
      a[i] = a[i+1];
      a[i+1] = temp;
    }
  }
  return;
}