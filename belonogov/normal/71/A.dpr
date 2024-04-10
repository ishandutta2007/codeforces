uses
  SysUtils;

var
  s, s1: string;
  i, n: longint;

begin
  readln(n);
  for i := 1 to n do
  begin
    readln(s);
    if length(s) > 10  then
    begin
      s1 := s[1] + inttostr(length(s) - 2) + s[length(s)];
      writeln(s1);
    end
    else
      writeln(s);
  end;

end.