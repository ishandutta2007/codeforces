program problem3;
type tArr = array[1..2000] of char;

function min( a, b: word ): word;
begin
  if a < b then
    min := a
  else
    min := b;
end;

var s, u: tArr;
    s_len, u_len, max, cnt, cnt2, i, j: word;
    c: string[1];

begin
  s_len := 0;
  max := 0;

  read(c);
  while c <> '' do
  begin
    inc( s_len );
    s[ s_len ] := c[1];
    read(c);
  end;
  readln;

  u_len := 0;

  read(c);
  while c <> '' do
  begin
    inc( u_len );
    u[ u_len ] := c[1];
    read(c);
  end;
  readln;

  for i := 1 to s_len do
  begin
    cnt := 0;
    for j := i to min( s_len, (i+u_len-1) ) do
    begin
      if s[j] = u[j-i+1] then
        inc( cnt );
    end;

    if ( cnt > max ) then
      max := cnt;
  end;

  for i := (u_len-1) downTo 1 do
  begin
    cnt := 0;
    for j := i downTo 1 do
    begin
      if s[j] = u[u_len-i+j] then
       inc( cnt );
    end;
    if ( cnt > max ) then
      max := cnt;
  end;

  writeln( u_len - max );
end.