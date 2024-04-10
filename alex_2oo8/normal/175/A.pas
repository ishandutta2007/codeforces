program problem1;
uses math;

var arr: array[1..21] of byte;

function numb( l, r: longWord ): longInt;
var i, a, res: longWord;
begin
  a := 1;
  res := 0;
  for i := r downTo l do
  begin
    res := res + ( arr[i] * a );
    a := a * 10;
  end;

  if ( res > 1000000 ) or ( ( arr[l] = 0 ) and ( r > l ) ) then
    numb := -1
  else
    numb := res;
end;

var chr: string[1];
    dp: array[ 1..21, 1..3 ] of longInt;
    i, j, k, cnt: longWord;
    m, c: longInt;

begin
  cnt := 0;

  read( chr );  while ( chr <> '' ) do
  while ( chr <> '' ) do
  begin
    inc( cnt );
    if ( cnt > 21 ) then
    begin
      writeln( '-1' );
      halt;
    end;

    arr[cnt] := ord( chr[1] ) - ord( '0' );

    read( chr );
  end;

  if ( cnt < 3 ) then
  begin
    writeln( '-1' );
    halt;
  end;

  for i := 1 to min( 7, (cnt-2) ) do
    dp[i][1] := numb( 1, i );

  for i := 2 to 3 do
  begin
    for j := i to min( (7*i), (cnt-3+i) ) do
    begin
      m := -1;
      for k := max( (i-1), (j-7) ) to min( 7*(i-1), (j-1) ) do
      begin
        c := numb( (k+1), j );
        if ( c > -1 ) and ( dp[k][i-1] > -1 ) and ( ( c + dp[k][i-1] ) > m ) then
          m := c + dp[k][i-1];
      end;
      dp[j][i] := m;
    end;
  end;

  writeln( dp[cnt][3] );
end.