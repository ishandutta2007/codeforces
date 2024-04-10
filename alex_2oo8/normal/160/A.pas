program problem1;
type tArr = array[1..100] of byte;

procedure sort( var a: tArr; l: byte );
var i, j, t: byte;
begin
  for i := 1 to l do
    for j := (i+1) to l do
      if ( a[j] > a[i] ) then
      begin
        t := a[i];
        a[i] := a[j];
        a[j] := t;
      end;
end;

var n, cnt, i: byte;
    s, sum: word;
    a: tArr;

begin
  s := 0;

  readln( n );
  for i := 1 to n do
  begin
    read( a[i] );
    s := s + a[i];
  end;
  sort( a, n );

  cnt := 0;
  sum := 0;
  while not( sum > (s/2) ) do
  begin
    inc( cnt );
    sum := sum + a[ cnt ];
  end;

  writeln( cnt );
end.