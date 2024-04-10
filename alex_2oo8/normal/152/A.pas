program problem1;
type tArr = array[0..100] of byte;

function getItem( str: string; i: byte ): byte;
begin
  getItem := ord( str[i] ) - ord( '0' );
end;

function new( a: byte; arr: tArr ): boolean;
var i: byte;
    b: boolean;
begin
  b := true;

  for i := 1 to arr[0] do
  begin
    if ( arr[i] = a ) then
    begin
      b := false;
      break;
    end;
  end;

  new := b;
end;

var n, m, i, j, item, cnt: byte;
    max: array[1..100, -1..100] of byte;
    old: tArr;
    str: string;

begin
  read( n );
  readln( m );

  for i := 1 to m do
  begin
    max[i][0] := 0;
    max[i][1] := 0;
  end;

  for i := 1 to n do
  begin
    readln( str );
    for j := 1 to m do
    begin
      item := getItem( str, j );
      if ( item > max[j][-1] ) then
      begin
        max[j][-1] := item;
        max[j][0] := 1;
        max[j][1] := i;
      end
      else if ( item = max[j][-1] ) then
      begin
        inc( max[j][0] );
        max[j][ max[j][0] ] := i;
      end;
    end;
  end;

  cnt := 0;
  for i := 1 to j do
  begin
    for j := 1 to max[i][0] do
    begin
      if ( new( max[i][j], old ) ) then
      begin
        inc( cnt );
        inc( old[0] );
        old[ old[0] ] := max[i][j];
      end;
    end;
  end;

  writeln( cnt );
end.