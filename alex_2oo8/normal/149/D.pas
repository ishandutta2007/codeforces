program problem4;

type tArr = array[ 0..2, 0..2 ] of qWord;

const d = 1000000007;

procedure proc( const str: ansistring; l, r: longWord; var res: tArr );
var i, j, b: longWord;
    arr1, arr2: tArr;
begin
  if ( (r-l) = 1 ) then
  begin
    res[0][0] := 0;
    res[0][1] := 1;
    res[0][2] := 1;
    res[1][0] := 1;
    res[1][1] := 0;
    res[1][2] := 0;
    res[2][0] := 1;
    res[2][1] := 0;
    res[2][2] := 0;
  end
  else
  begin
    b := 1;
    i := l;
    while ( b > 0 ) do
    begin
      inc( i );
      if ( str[i] = '(' ) then
        inc( b )
      else if ( str[i] = ')' ) then
        dec( b );
    end;

    if ( i = r ) then
    begin
      proc( str, (l+1), (r-1), arr1 );
      res[0][0] := 0;
      res[0][1] := ( arr1[0][0] + arr1[0][2] + arr1[1][0] + arr1[1][2] + arr1[2][0] + arr1[2][2] ) mod d;
      res[0][2] := ( arr1[0][0] + arr1[0][1] + arr1[1][0] + arr1[1][1] + arr1[2][0] + arr1[2][1] ) mod d;
      res[1][0] := ( arr1[0][0] + arr1[0][1] + arr1[0][2] + arr1[2][0] + arr1[2][1] + arr1[2][2] ) mod d;
      res[1][1] := 0;
      res[1][2] := 0;
      res[2][0] := ( arr1[0][0] + arr1[0][1] + arr1[0][2] + arr1[1][0] + arr1[1][1] + arr1[1][2] ) mod d;
      res[2][1] := 0;
      res[2][2] := 0;
    end
    else
    begin
      proc( str, l, i, arr1 );
      proc( str, (i+1), r, arr2 );

      for i := 0 to 2 do
        for j := 0 to 2 do
          res[i][j] := ( ( ( ( arr1[i][0] + arr1[i][1] + arr1[i][2] ) mod d ) * arr2[0][j] ) mod d +
                         ( ( ( arr1[i][0] + arr1[i][1]              ) mod d ) * arr2[2][j] ) mod d +
                         ( ( ( arr1[i][0] + arr1[i][2]              ) mod d ) * arr2[1][j] ) mod d ) mod d;
    end;
  end;
end;

var str: ansistring;
    arr: tArr;
    ans, i, j: longWord;

begin
  readln( str );

  proc( str, 1, length(str), arr );

  ans := 0;
  for i := 0 to 2 do
    for j := 0 to 2 do
      ans := ( ans + arr[i][j] ) mod d;

  writeln( ans );
end.