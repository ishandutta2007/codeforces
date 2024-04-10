{$APPTYPE CONSOLE}
var
  a: array[1..1000] of longint;
  b: array[1..1000] of longint;
  i, rez, n: longint;

function srav(x, y: longint): boolean;
var
  kol: longint;
begin
  kol := 0;
  srav := false;
  if (x mod 10 <> y mod 10) then inc(kol);
  x := x div 10;
  y := y div 10;
  if (x mod 10 <> y mod 10) then inc(kol);
  x := x div 10;
  y := y div 10;
  if (x mod 10 <> y mod 10) then inc(kol);
  x := x div 10;
  y := y div 10;
  if (x mod 10 <> y mod 10) then inc(kol);

  if kol <= 1 then srav := true;
end;


function asd(k0, k: longint): longint;
var
  i: longint;
  check: boolean;

begin
  i := k0;
  check := false;
  while (i <= 2011) and (not check) do
  begin
    if srav(i, k) then
    begin
      asd := i;
      check := true;
    end;
    inc(i);
  end;
  if not check then rez := -1;

end;

begin
  read(n);
  rez := 0;
  for i := 1 to n do
    read(a[i]);

  b[1] := asd(1000, a[1]);
  for i := 2 to n do
    b[i] := asd(b[i - 1], a[i]);

  if rez <> -1 then
    for i := 1 to n do
      writeln(b[i])
  else
    writeln('No solution');

end.