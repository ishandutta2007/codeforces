/* You agree on two arrays
 * of integers M and R, 
 * number of upcoming days
 * (including the current one)
 * with successive integers,
 * and you wash the dishes on 
 * day D iff there exists an 
 * index i such that 
 * D mod M[i] = R[i], otherwise
 * your roommate does it.
 * You like the concept, but
 * your roommate's cunning smile
 * makes you suspect something,
 * so you intend to verify the
 * fairness of the arrangement
 *
 * You are given arrays M and R
 * Calculate the percentage of
 * days on which you end up
 * doing the washing. Assume that
 * you have infinitely many
 * days ahead of you. */

#include <iostream>
#include <iomanip>

typedef long double ldouble;

const int LCM = 720720;
const int MAX_SIZE = 16;

using namespace std;

int mod [MAX_SIZE], result [MAX_SIZE];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> mod[i];
  }

  for (int i = 0; i < length; i++) {
    cin >> result[i];
  }
  
  int total = 0;
  for (int i = 0; i < LCM; i++) {
    bool flag = false;
    for (int j = 0; j < length; j++) {
      if (i % mod[j] == result[j]) {
        flag = true;
      }
    }
    if (flag) {
      total++;
    }
  }

  cout << fixed << setprecision(20)
       << (ldouble) total / (ldouble) LCM << endl;
}