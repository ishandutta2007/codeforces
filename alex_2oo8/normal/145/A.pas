program problem1;
type tArr = array[0..393] of string;

procedure check( a, b: tArr; n: word; var to7, to4: longWord );
var s1, s2: string;
    i, j: word;
begin
  for i := 0 to n do
  begin
    s1 := a[i];
    s2 := b[i];
    for j := 1 to length( s1 ) do
    begin
      if ( s1[j] = '4' ) and ( s2[j] = '7' ) then
        inc( to7 )
      else if ( s1[j] = '7' ) and ( s2[j] = '4' ) then
        inc( to4 );
    end;
  end;
end;

function min( a, b: longWord ): longWord;
begin
  if ( a < b ) then
    min := a
  else
    min := b;
end;

var a, b: tArr;
    i: word;
    str: string;
    to7, to4: longWord;

begin
  i := 0;
  to7 := 0;
  to4 := 0;

  read( str );
  while ( length( str ) > 0 ) do
  begin
    a[i] := str;
    inc( i );
    read( str );
  end;
  readln;
  i := 0;
  read( str );
  while ( length( str ) > 0 ) do
  begin
    b[i] := str;
    inc( i );
    read( str );
  end;
  readln;

  check( a, b, (i-1), to7, to4 );

  writeln( min( to7, to4 ) + abs( to7 - to4 ) );
end.