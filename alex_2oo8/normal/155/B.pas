program prblem2;
type tArr = array[1..10000, 'a'..'b'] of word;

procedure sort( var a: tArr; n: word );
var i, j, t: word;
begin
  for i := 1 to n do
  begin
    for j := ( i + 1 ) to n do
    begin
      if ( a[i]['b'] < a[j]['b'] ) or ( ( a[i]['b'] = a[j]['b'] ) and ( a[i]['a'] < a[j]['a'] ) ) then
      begin
        t := a[i]['a'];
        a[i]['a'] := a[j]['a'];
        a[j]['a'] := t;
        t := a[i]['b'];
        a[i]['b'] := a[j]['b'];
        a[j]['b'] := t;
      end;
    end;
  end;
end;

var n, i: word;
    p, t: longWord;
    c: tArr;

begin
  p := 0;
  t := 1;

  readln( n );
  for i := 1 to n do
  begin
    read  ( c[i]['a'] );
    readln( c[i]['b'] );
  end;

  sort( c, n );

  for i := 1 to n do
  begin
    dec( t );
    p := p + c[i]['a'];
    t := t + c[i]['b'];

    if ( t = 0 ) then
      break;
  end;

  writeln( p );
end.