program problem2;
type tArr = array[1..100] of word;

procedure sort( var a: tArr; n: byte );
var i, j: byte;
    t: word;
begin
  for i := 1 to n do
    for j := ( i + 1 ) to n do
    begin
      if ( a[i] < a[j] ) then
      begin
        t := a[i];
        a[i] := a[j];
        a[j] := t;
      end;
    end;
end;

var n, i: byte;
    pi: real;
    r: tArr;
    s: double;

begin
  pi := 3.141592653589793;
  s := 0;

  readln( n );
  for i := 1 to n do
    read( r[i] );
  readln;

  sort( r, n );

  for i := 1 to n do
  begin
    if ( i mod 2 ) = 1 then
      s := s + ( pi * r[i] * r[i] )
    else
      s := s - ( pi * r[i] * r[i] );
  end;

  writeln( s:7:10 );
end.