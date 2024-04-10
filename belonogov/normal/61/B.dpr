var
  a: array[1..1000] of string;
  b: array[1..6] of string;
  s1, s2, s3, s: string;
  i, j, n: longint;
  check: boolean;

function red(s: string): string;
var
  s1: string;
  i: longint;

begin
  s1 := '';
  for i := 1 to length(s) do
  begin
    if (ord(s[i]) >= ord('A')) and (ord(s[i]) <= ord('Z')) then
      s1 := s1 + chr(ord(s[i]) - ord('A') + ord('a'));
    if (ord(s[i]) >= ord('a')) and (ord(s[i]) <= ord('z')) then s1 := s1 + s[i];
  end;
  red := s1;

end;


begin
  readln(s1);
  readln(s2);
  readln(s3);
  readln(n);
  s1 := red(s1);
  s2 := red(s2);
  s3 := red(s3);
  for i := 1 to n do
  begin
    readln(s);
    a[i] := red(s);
  end;
  b[1] := s1 + s2 + s3;
  b[2] := s1 + s3 + s2;
  b[3] := s2 + s1 + s3;
  b[4] := s2 + s3 + s1;
  b[5] := s3 + s1 + s2;
  b[6] := s3 + s2 + s1;
  for i := 1 to n do
  begin
    check := false;
    for j := 1 to 6 do
      if b[j] = a[i] then check := true;
    if check then writeln('ACC') else writeln('WA');
  end;
end.