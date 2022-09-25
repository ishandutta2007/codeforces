program taskD6;

var p: array[1..1000] of longWord;

function find( v: longWord ): longWord;
var n, i: longWord;
    arr: array[1..1000] of longWord;
begin
  n := 0;

  while ( p[v] <> 0 ) do
  begin
    inc( n );
    arr[n] := v;

    v := p[v];
  end;

  for i := 1 to n do
    p[ arr[i] ] := v;

  find := v;
end;

var n, i, j, u, v, ur, vr, ans: longWord;
    ans_arr: array[ 1..1000, 0..3 ] of longWord;

begin
  ans := 0;

  readln( n );
  for i := 1 to n do
    p[i] := 0;

  for i := 1 to (n-1) do
  begin
    readln( u, v );

    ur := find( u );
    vr := find( v );

    if ( vr = ur ) then
    begin
      inc( ans );
      ans_arr[ans][0] := u;
      ans_arr[ans][1] := v;
    end
    else
      p[ur] := vr;
  end;

  i := 1;
  while ( p[i] <> 0 ) do
    inc( i );

  j := i + 1;
  for u := 1 to ans do
  begin
    while ( p[j] <> 0 ) do
      inc( j );

    ans_arr[u][2] := i;
    ans_arr[u][3] := j;

    inc( j );
  end;

  writeln( ans );
  for i := 1 to ans do
    writeln( ans_arr[i][0], ' ', ans_arr[i][1], ' ', ans_arr[i][2], ' ', ans_arr[i][3] );
end.