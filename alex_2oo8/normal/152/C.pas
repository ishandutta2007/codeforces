program problem3;
const d = 1000000007;

var n, m, i, j: longWord;
    arr: array[ 1..100, 'A'..'Z' ] of boolean;
    chr: char;
    ans: qWord;

begin
  readln( n, m );

  for i := 1 to m do
    for chr := 'A' to 'Z' do
      arr[i][chr] := false;

  for i := 1 to n do
  begin
    for j := 1 to m do
    begin
      read( chr );
      arr[j][chr] := true;
    end;
    readln;
  end;

  ans := 1;

  for i := 1 to m do
  begin
    j := 0;
    for chr := 'A' to 'Z' do
      if ( arr[i][chr] ) then
        inc( j );

    ans := ( ans * j ) mod d;
  end;

  writeln( ans );
end.