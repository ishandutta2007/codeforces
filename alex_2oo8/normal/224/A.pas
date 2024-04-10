program problem1;

var s1, s2, s3, a, b, c: longWord;

begin
  readln( s1, s2, s3 );
  for a := 1 to s1 do
    if ( (s1 mod a) = 0 ) and ( (s2 mod a) = 0 ) then
    begin
      b := s1 div a;
      c := s2 div a;

      if ( (b*c) = s3 ) then
      begin
        writeln( 4 * (a+b+c) );
        halt;
      end;
    end;
end.