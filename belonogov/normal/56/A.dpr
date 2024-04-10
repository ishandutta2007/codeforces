{$O-}
const
  a: array[1..11] of string = ('ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE');

var
  s: string;
  i, n, sum, j: longint;
  check: boolean;

begin
  readln(n);
  sum := 0;
  for i := 1 to n do
  begin
    readln(s);
    if (ord(s[1]) >= ord('0')) and (ord(s[1]) <= ord('9')) and (length(s) < 3) then
      if not ((length(s) = 2) and (s >= '18')) then inc(sum);

    if not ((ord(s[1]) >= ord('0')) and (ord(s[1]) <= ord('9'))) then
    begin
      check := true;
      for j := 1 to 11 do
        if s = a[j] then check := false;
      if not check then  inc(sum);
    end;
  end;
  writeln(sum);

end.