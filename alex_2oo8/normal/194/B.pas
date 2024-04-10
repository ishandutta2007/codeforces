program problem2;

function NOD( a, b: longWord ): longWord;
var t: longWord;
begin
  while ( b <> 0 ) do
  begin
    a := a mod b;
    t := a;
    a := b;
    b := t;
  end;

  NOD := a;
end;

var t, i: longWord;
    ans, n, ax: qWord;

begin
  readln( t );
  for i := 1 to t do
  begin
    read( n );
    ax := ( (4*n) div NOD( (n+1), (4*n) ) ) * (n+1);
    ans := (ax-1) div (n+1) + 2;
    writeln( ans );
  end;
end.