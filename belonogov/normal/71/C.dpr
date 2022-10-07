uses
  SysUtils;

var
  a: array[1..100000] of longint;
  i, n, start, j: longint;
  check, check1: boolean;

begin
  read(n);
  for i := 1 to n do
    read(a[i]);

  check := false;
  for i := 1 to n div 3 do
    if n mod i = 0 then
    begin
      for start := 1 to i do
      begin
        check1 := true;
        for j := 1 to n div i do
          if a[(start + j * i - 1) mod n + 1] = 0 then
            check1 := false;
        if check1  then check := true;
       end;
    end;

  if check then
    writeln('YES')
  else
    writeln('NO');

end.