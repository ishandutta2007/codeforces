uses math;
var
  s:string;
  na,naa:longint;
  i:longint;
function big(c:char):char;
  begin
         if (ord(c)>=97) and (ord(c)<=122) then c:=chr(ord(c)-32)
    else if (ord(c)>=65) and (ord(c)<=90) then c:=chr(ord(c)+32);
    exit(c);
  end;
begin
  read(s);
  naa:=0;
  na:=0;
  for i:=1 to length(s) do
    if (ord(s[i])>=97) and (ord(s[i])<=122) then inc(naa)
    else inc(na);

  for i:=1 to length(s) do
    begin
      if (naa<na) and (ord(s[i])>=97) and (ord(s[i])<=122) then write(big(s[i]))
      else if (na<=naa) and (ord(s[i])>=65) and (ord(s[i])<=90) then write(big(s[i]))
      else write(s[i]);
    end;
end.