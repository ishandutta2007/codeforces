Program CodeF_425_A;
var n,k:int64;
begin
read(n,k);
if (n div k) mod 2=1 then write('YES') else
  write('NO');
end.