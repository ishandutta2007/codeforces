<?php
  $input = (int)trim(fgets(STDIN));
  $hola = explode(' ',trim(fgets(STDIN)));
  $even=0;
  $odd=0;
  for($x=0; $x<$input; $x++)
  {
    if($hola[$x]%2==0)
      $even++;
    else {
      $odd++;
    }
  }
  if($even>=$odd)
    echo $odd;
  else {
    echo $even + ($odd-$even-($odd-$even)%3)/3;
  }
 ?>