const
  base = 10000;
  long = 100;
  
type
  Tlong = record
    a: array[1..long] of longint;
    long: longint;
  end;
{///////////////////////}
var
  a, s1: Tlong;
  s: string;
{///////////////////////}
function strtoint(s: string): longint;
var
  i, x, sum: longint;
begin
  x := length(s);
  sum := 0;
  for i := 1 to x do
    sum := sum * 10 + ord(s[i]) - ord('1') + 1;

  strtoint := sum;

end;
{////////////////////////}
function readlong(s: string): Tlong;
var
  x, i: longint;

begin
  x := length(s);
  for i := 1 to long do
    readlong.a[i] := 0;
  readlong.long := (x + 3) div 4;
  for i := 1 to (x + 3) div 4 do
  begin
    if x - (i * 4) >= 0 then
      readlong.a[i] := strtoint(copy(s, x + 1 - (i * 4), 4))
    else
    if x < 4  then
      readlong.a[i] := strtoint(copy(s, 1, x))
    else
      readlong.a[i] := strtoint(copy(s, 1, x - (i - 1) * 4));

  end;
end;


procedure writelong(c: Tlong);
var
  i: longint;

begin
  write(c.a[c.long]);
  for i := c.long - 1 downto 1 do
  begin
    if (c.a[i] >= 1000) then write(c.a[i]);
    if (c.a[i] < 1000) and (c.a[i] >= 100) then write('0', c.a[i]);
    if (c.a[i] < 100) and (c.a[i] >= 10) then write('00', c.a[i]);
    if (c.a[i] < 10) then write('000', c.a[i]);
  end;
end;

function srav(a, b: tlong): boolean;
var
  i: longint;
  srav1: boolean;

begin
  if a.long > b.long then srav := true;
  if a.long < b.long then srav := false;
  if a.long = b.long then
  begin
    i := a.long;
    while (a.a[i] = b.a[i]) and (i >= 1) do
      dec(i);

    if i = 0 then srav := true;
    if (i <> 0) and (a.a[i] > b.a[i]) then srav := true;;
    if (i <> 0) and (a.a[i] < b.a[i]) then srav := false;;
  end;


end;

{////////////////////////}
begin
  readln(s);
  a := readlong(s);
  s1 := readlong('127');
  if srav(s1, a) then
  begin
    writeln('byte');
    exit;
  end;
  s1 := readlong('32767');
  if srav(s1, a) then
  begin
    writeln('short');
    exit;
  end;

  s1 := readlong('2147483647');
  if srav(s1, a) then
  begin
    writeln('int');
    exit;
  end;

  s1 := readlong('9223372036854775807');
  if srav(s1, a) then
  begin
    writeln('long');
    exit;
  end;
  writeln('BigInteger');

end.