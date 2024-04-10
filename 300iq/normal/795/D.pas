program YYYY;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  n, m, l, i, j, r, f, f1, ar: integer;
  a: array [-100000..1000000] of integer;
  b: array [-100000..1000000] of integer;
begin
  readln(n, l, r);
  for i := 1 to n do
  begin
    read(a[i]);
  end;
  for i := 1 to n do
  begin
    read(b[i]);
  end;
  for i := 1 to l-1 do
  begin
    if not (a[i] = b[i]) then
    begin
        writeln('LIE');
        halt(0);
    end;
  end;
    for i := r+1 to n do
  begin
    if not (a[i] = b[i]) then
    begin
        writeln('LIE');
        halt(0);
    end;
  end;
  writeln('TRUTH');
end.