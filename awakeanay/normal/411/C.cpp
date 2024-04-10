/*
Author: AwakeAnay
Date: 14/02/2020
Time: 16:58:35
*/

#include <iostream>

int main() {
  int players[4][2];
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 2; j++)
      std::cin >> players[i][j];

  bool team1 = ((players[0][1] > players[3][0]) & (players[1][0] > players[2][1]) & (players[0][1] > players[2][0]) & (players[1][0] > players[3][1])) |
               ((players[1][1] > players[3][0]) & (players[0][0] > players[2][1]) & (players[1][1] > players[2][0]) & (players[0][0] > players[3][1]));

  bool team2 = ((players[0][1] < players[3][0] & players[1][0] < players[2][1]) | (players[0][1] < players[2][0] & players[1][0] < players[3][1])) &
               ((players[1][1] < players[3][0] & players[0][0] < players[2][1]) | (players[1][1] < players[2][0] & players[0][0] < players[3][1]));

  if(team1)
    std::cout << "Team 1";
  else if(team2)
    std::cout << "Team 2";
  else
    std::cout << "Draw";

  std::cout << std::endl;

  return 0;
}