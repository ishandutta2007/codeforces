program problem4;

var w, b, i, j: longWord;
    arr: array[ 0..1000, 0..1000, 0..1 ] of real;

begin
  readln( w, b );
  arr[0][0][0] := 0.0;
  arr[0][0][1] := 0.0;
  for i := 1 to b do
  begin
    arr[0][i][0] := 0.0;
    arr[0][i][1] := 0.0;
  end;


  for i := 1 to w do
  begin
    arr[i][0][0] := 1.0;
    arr[i][0][1] := 0.0;
    for j := 1 to b do
    begin
      arr[i][j][0] := ( i / (i+j) ) + ( j / (i+j) ) * arr[i][j-1][1];
      arr[i][j][1] := ( j / (i+j) ) * ( i / (i+j-1) ) * arr[i-1][j-1][0];
      if ( j >= 2 ) then
        arr[i][j][1] := arr[i][j][1] + ( ( j / (i+j) ) * ( (j-1) / (i+j-1) ) * arr[i][j-2][0] );
    end;
  end;

  writeln( arr[w][b][0]:0:12 );
end.