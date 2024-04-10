program problem2;
type tArr = array[1..100] of byte;

procedure sort( var a, b: tArr; l: byte );
var i, j, t: byte;
begin
  for i := 1 to l do
    for j := (i+1) to l do
    begin
      if ( a[j] > a[i] ) then
      begin
        t := a[i];
        a[i] := a[j];
        a[j] := t;
      end;
      if ( b[j] > b[i] ) then
      begin
        t := b[i];
        b[i] := b[j];
        b[j] := t;
      end;
    end;
end;

var n, i: byte;
    a, b: tArr;
    bool1, bool2: boolean;
    chr: char;

begin
  readln( n );
  for i := 1 to n do
  begin
    read( chr );
    a[i] := ord( chr ) - ord( '0' );
  end;
  for i := 1 to n do
  begin
    read( chr );
    b[i] := ord( chr ) - ord( '0' );
  end;

  sort( a, b, n );

  bool1 := true;
  bool2 := true;
  for i := 1 to n do
  begin
    if ( bool1 and ( a[i] <= b[i] ) ) then
      bool1 := false;
    if ( bool2 and ( b[i] <= a[i] ) ) then
      bool2 := false;
  end;

  if bool1 or bool2 then
    writeln( 'YES' )
  else
    writeln( 'NO' );
end.