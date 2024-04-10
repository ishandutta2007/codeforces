const
  c: array[1..3] of string = ('paper', 'scissors', 'rock');

var
  a: array[1..100] of longint;
  b: array[1..100] of string;
  check: boolean;
  i: longint;

procedure answer(i: longint);
var
  j, k: longint;

begin
  k := 0;
  for j := 1 to 3 do
    if b[j] = c[i] then k := j;

  if k = 1 then writeln('F');
  if k = 2 then writeln('M');
  if k = 3 then writeln('S');


end;


begin
  for i := 1  to 3 do
  begin
    readln(b[i]);
    if b[i] = 'paper' then inc(a[1]);
    if b[i] = 'scissors' then inc(a[2]);
    if b[i] = 'rock' then inc(a[3]);
  end;
  check := false;

  if (a[1] = 1) and  (a[3] = 2) then
  begin
    answer(1);
    check := true;
  end;
  if (a[2] = 1) and  (a[1] = 2) then
  begin
    answer(2);
    check := true;
  end;
  if (a[3] = 1) and  (a[2] = 2) then
  begin
    answer(3);
    check := true;
  end;
  if not check then writeln('?')

end.